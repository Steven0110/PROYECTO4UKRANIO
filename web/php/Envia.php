<?php
//$palabra = "hola";
$palabra = $_POST['cadena'];


//$dir_subida = $dir_subida . basename($_FILES['uploadfile']['name']);
//IP LAURA: 192.168.43.232
//IP STEVEN: 192.168.43.107
//IP BRIAN: 192.168.43.206

$MAX_UDP = 1024;
$server_laura   = [
  "ip" => "192.168.43.232",
  "status" => 0,
  "min" => 0,
  "max" => 0,
  "name" => "Laura"
];
$server_brian   = [
  "ip" => "192.168.43.206",
  "status" => 0,
  "min" => 0,
  "max" => 0,
  "name" => "Brian"
];
$server_steven   = [
  "ip" => "192.168.43.107",
  "status" => 0,
  "min" => 0,
  "max" => 0,
  "name" => "Steven"
];
$servers = [
  $server_steven, $server_brian, $server_laura
];

$server_port = 7201;
$beat_period = 5;
$micro_beat_period = 100;
$array = array();
if ( ($socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP)) == false ) {
  echo "{ \"status\" : \"-1 \"}";
  exit(-1);
}else{
      //Obtiene las PCs que están activas - SERVICIO EN EL PUERTO 7202
  $code = "2";
  $pc_no = 0;
  $i = 0;
  socket_set_option($socket, SOL_SOCKET, SO_RCVTIMEO, array("sec"=>1,"usec"=>0));
  foreach( $servers as $server ){
    //Pregunta a cada servidor si está encendido:
    socket_sendto($socket, $code, strlen($code), 0, $server["ip"], 7202);
    //Recibe su respuesta
    if(socket_recv ( $socket , $reply , 1024 , MSG_WAITALL ) === FALSE){
    }else{
      $pc_no++;
      $servers[$i]["status"] = 1;
      //echo "Respondió ".$server["name"]."\n";
    }
    $i++;
  }

    //Pregunta por la cantidad total de archivos server por server hasta que uno le responda
  //  SERVICIO EN EL PUERTO 7203
  $code = "3";
  $files = 0;
  $i=0;
  foreach( $servers as $server ){
    socket_sendto($socket, $code, strlen($code), 0, $server["ip"], 7203);
    //Recibe su respuesta
    if(socket_recv ( $socket , $reply , 2 , MSG_WAITALL ) === FALSE){
    }else{
      $files = intval($reply);
      break;
    }
  }
  //echo "Hay ".$files." archivos\n";
  //Define los rangos que le tocan a cada computadora
  $count = 0;
  $files_per_pc = floor( $files / $pc_no );
  $i = 0;
  foreach( $servers as $server ){
    if($server["status"]  == 1 ){
      $servers[$i]["min"]  = $count * $files_per_pc;
      $servers[$i]["max"]  = $count * $files_per_pc + $files_per_pc - 1;
      $count++;
    }
    $i++;
  }
  //Le envía sus rangos a cada server activo y la palabra - SERVICIO EN EL PUERTO 7201
  $i = 0;
  //var_dump($servers);
  foreach($servers as $server ){
    if($server["status"] == 1 ){
      $min = "".$server["min"] ;
      $max = "".$server["max"] ;
      socket_sendto($socket, $min, strlen($min), 0, $server["ip"], $server_port);
      usleep($micro_beat_period);
      socket_sendto($socket, $max, strlen($max), 0, $server["ip"], $server_port);
      usleep($micro_beat_period);
      socket_sendto($socket, $palabra, strlen($palabra), 0, $server["ip"], $server_port);
      usleep($micro_beat_period);
      echo "A ".$server["name"]." le tocó de $min a $max\n";
    }
  }
  //Espera hasta recibir la respuesta de los servers
  while( 1 ){
      if(socket_recv ( $socket , $reply , 1024 , MSG_WAITALL ) === FALSE){
        exit(1);
      }else{
        echo $reply." \n";
      }
  }
}
?>
