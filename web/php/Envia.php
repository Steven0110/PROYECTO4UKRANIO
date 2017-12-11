<?php
$palabra = $_POST['cadena'];
//$dir_subida = $dir_subida . basename($_FILES['uploadfile']['name']);
//IP LAURA: 192.168.43.232
$MAX_UDP = 1024;
$server_ip   = '192.168.43.232';
$server_port = 7201;
$beat_period = 5;
$micro_beat_period = 100;

if ($socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP)) {
    socket_sendto($socket, $palabra, strlen($palabra), 0, $server_ip, $server_port);
    while( 1 ){
  		if(socket_recv ( $sock , $reply , 1024 , MSG_WAITALL ) === FALSE){
        $errorcode = socket_last_error();
        $errormsg = socket_strerror($errorcode);
        die("Could not receive data: [$errorcode] $errormsg \n");
      }
      echo $reply;
    }
  //Respuesta JSON
  echo "{ \"status\" : \"1\"}";
} else {
  echo "{ \"status\" : \"-1\"}";
}
?>
