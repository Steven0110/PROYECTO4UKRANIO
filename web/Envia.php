<?php
$palabra = $_POST['cadena'];
//$dir_subida = $dir_subida . basename($_FILES['uploadfile']['name']);
//IP LAURA: 192.168.43.232
$MAX_UDP = 1024;
$server_ip   = '192.168.43.232';
$server_port = 7201;
$beat_period = 5;
$micro_beat_period = 100;
//print "Sending heartbeat to IP $server_ip, port $server_portn";
//print "press Ctrl-C to stopn";
/*
if (move_uploaded_file($_FILES['fichero_usuario']['tmp_name'], $fichero_subido)) {
    echo "El fichero es válido y se subió con éxito.\n";
} else {
    echo "¡Posible ataque de subida de ficheros!\n";
}*/

if ($socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP)) {
  while (1) {
    socket_sendto($socket, $palabra, 0, $server_ip, $server_port);
    usleep($micro_beat_period );
    socket_sendto($socket, $palabra, 0, $server_ip, $server_port);
    print("Mensaje enviado...\n");
    sleep($beat_period);
  }
} else {
  print("can't create socket\n");
}
?>
