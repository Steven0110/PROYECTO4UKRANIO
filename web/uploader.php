<?php

  /*$uploadedfileload="true";
  $uploadedfile_size=$_FILES[uploadedfile][size];
  echo $_FILES['uploadedfile'][name];
  if ($_FILES['uploadedfile']['size']>1000000){
    $msg=$msg."El archivo es mayor que 1000KB, debes reduzcirlo antes de subirlo<BR>";
    $uploadedfileload="false";}
    if (!($_FILES['uploadedfile'][type] =="text/plain")){
      $msg=$msg." Tu archivo tiene que ser de texto. Otros archivos no son permitidos<BR>";
      $uploadedfileload="false";
    }

  $file_name=$_FILES['uploadedfile']['name'];
  $add="Uploads/$file_name";
  if($uploadedfileload=="true"){
    if(move_uploaded_file ($_FILES['uploadedfile']['tmp_name'], "Uploads")){
      echo " Ha sido subido satisfactoriamente<br>";
    }else{
      echo " Error al subir el archivo<br>";
    }
  }else{
    echo $msg;
  }*/
/*if(move_uploaded_file($_FILES['uploadedfile']['tmp_name'], $add)){
    echo"se movio correctamente";
  }else {
    var_dump($_FILES['uploadedfile']['tmp_name'], $add);
  }
  if (is_uploaded_file($_FILES['uploadedfile']['tmp_name'])) {
   echo "Archivo ". $_FILES['uploadedfile']['name'] ." subido con éxtio.\n";
   echo "Mostrar contenido\n";
   readfile($_FILES['uploadedfile']['tmp_name']);
 } else {
   echo "Posible ataque del archivo subido: ";
   echo "nombre del archivo '". $_FILES['uploadedfile']['tmp_name'] . "'.";
 }*/
?>
