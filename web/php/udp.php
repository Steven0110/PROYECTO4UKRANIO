<?php
//IP LAURA: 192.168.43.232
$MAX_UDP = 1024;
$server_ip   = '192.168.43.232';
$server_port = 7201;
$beat_period = 5;
$micro_beat_period = 100;
$filename     = 'prueba.txt';
$message     = 'Hola Lau :)';
$filename = $_FILES["file"]["name"];
$message = file_get_contents($_FILES["file"]["tmp_name"]);
if ($socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP)) {
  socket_sendto($socket, $filename, strlen($message), 0, $server_ip, $server_port);
  usleep($micro_beat_period );
  socket_sendto($socket, $message, strlen($message), 0, $server_ip, $server_port);
  print("Mensaje enviado...\n");
} else {
  print("can't create socket\n");
}
?>
