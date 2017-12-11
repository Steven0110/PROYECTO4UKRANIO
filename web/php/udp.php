<?php
//$server_ip   = '127.0.0.1';
/*$dir_subida = $dir_subida . basename($_FILES['uploadfile']['name']);
$server_ip   = '192.168.43.232';*/
$server_port = 7201;
$server_ip   = '192.168.43.232';
$beat_period = 5;
$message     = 'Hola Lau :)';
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
    socket_sendto($socket, $message, strlen($message), 0, $server_ip, $server_port);
    sleep(5);
  }
} else {
  print("can't create socketn");
}
?>
