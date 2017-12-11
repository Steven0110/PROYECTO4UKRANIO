<?php
//IP LAURA: 192.168.43.232
$MAX_UDP = 1024;
$server_ip   = '192.168.43.232'; //Laura
$server_ip_b   = '192.168.43.206'; //Brian
$server_ip_s  = '192.168.43.107'; //Steven
$server_port = 7201;
$beat_period = 5;
$micro_beat_period = 100;
$filename     = 'prueba.txt';
$message     = 'Hola Lau :)';
$filename = $_FILES["file"]["name"];
$filename = "../res/".$filename;
$message = file_get_contents($_FILES["file"]["tmp_name"]);
if ($socket = socket_create(AF_INET, SOCK_DGRAM, SOL_UDP)) {
	//Envía a Laura
  socket_sendto($socket, $filename, strlen($filename), 0, $server_ip, $server_port);
  usleep($micro_beat_period );
  socket_sendto($socket, $message, strlen($message), 0, $server_ip, $server_port);

	//Envía a Brian
  socket_sendto($socket, $filename, strlen($filename), 0, $server_ip_b, $server_port);
  usleep($micro_beat_period );
  socket_sendto($socket, $message, strlen($message), 0, $server_ip_b, $server_port);

	//Envía a Steven
  socket_sendto($socket, $filename, strlen($filename), 0, $server_ip_s, $server_port);
  usleep($micro_beat_period );
  socket_sendto($socket, $message, strlen($message), 0, $server_ip_s, $server_port);

  //Respuesta JSON
  echo "{ \"status\" : \"1\"}";
} else {
  echo "{ \"status\" : \"-1\"}";
}
?>
