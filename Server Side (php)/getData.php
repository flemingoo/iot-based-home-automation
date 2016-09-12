<?php

DEFINE('DB_USER','digitale_shUser');
DEFINE('DB_PASSWORD','NbL]Ceb*{tF7');
DEFINE('DB_HOST','localhost');
DEFINE('DB_NAME','digitale_sHomeDb');
DEFINE('DB_PORT','3306');

if($_SERVER["REQUEST_METHOD"]="POST"){
	
	$conn= mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME,DB_PORT) OR die('Could not connect to MySQL:'.mysqli_connect_error());
	
	$query = "SELECT * FROM thresholds_auto";
	$response = @mysqli_query($conn,$query);
	$number_of_rows = mysqli_num_rows($response);
	if($number_of_rows > 0)
	{
		while($row = mysqli_fetch_assoc($response))
		{
			$temp_array[] = $row;	
		}
	}
	header('Content-type: application/json');
	echo json_encode(array("Thresholds" => $temp_array));
	mysqli_close($conn);
		
	}
?>
