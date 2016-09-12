<?php

DEFINE('DB_USER','digitale_shUser');
DEFINE('DB_PASSWORD','NbL]Ceb*{tF7');
DEFINE('DB_HOST','localhost');
DEFINE('DB_NAME','digitale_sHomeDb');
DEFINE('DB_PORT','3306');

if($_SERVER["REQUEST_METHOD"]="POST"){
	
	$conn= mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME,DB_PORT) OR die('Could not connect to MySQL:'.mysqli_connect_error());
	
	$node=$_POST['node'];
	if($_POST['light']){
		$field='light';
		$fieldValue=$_POST['light'];
	}
	if($_POST['hvac']){
		$field='hvac';
		$fieldValue=$_POST['hvac'];
	}
	if($_POST['window']){
		$field='window';
		$fieldValue=$_POST['window'];
	}
	if($_POST['pir']){
		$field='pir';
		$fieldValue==$_POST['pir'];
	}
	//$query="INSERT INTO 'digitale_sHomeDb'.'thresholds_auto' ('node', 'light', 'hvac', 'window', 'pir') VALUES ('', '200', '', '', '')";
	$query = "UPDATE thresholds_auto SET $field='$fieldValue' WHERE node='$node'";
	$response = mysqli_query($conn,$query);
	echo $query;
	
	mysqli_close($conn);
		
	}
?>
