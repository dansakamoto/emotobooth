<?php

function base64_to_jpeg($base64_string, $output_file) {
    $ifp = fopen($output_file, "wb"); 

    fwrite($ifp, base64_decode($base64_string)); 
    fclose($ifp); 

    return $output_file; 
}

function encodeEmotion($emotion){

		$emotion = str_replace(":", "_colon_", $emotion);
		$emotion = str_replace("-", "_dash_", $emotion);
		$emotion = str_replace("(", "_openparen_", $emotion);
		$emotion = str_replace(")", "_closeparen_", $emotion);
		$emotion = str_replace(" ", "_space_", $emotion);
		$emotion = str_replace(",", "_comma_", $emotion);
		$emotion = str_replace("'", "_apostrophe_", $emotion);
		$emotion = str_replace("|", "_bar_", $emotion);
		$emotion = str_replace("\\", "_backslash_", $emotion);
		$emotion = str_replace("/", "_slash_", $emotion);
		$emotion = str_replace("<", "_greaterthan_", $emotion);
		$emotion = str_replace(">", "_lessthan_", $emotion);
		$emotion = str_replace("*", "_asterix_", $emotion);
		$emotion = str_replace(",", "_period_", $emotion);
		$emotion = str_replace("^", "_caret_", $emotion);
		
		return $emotion;
}


$face = $_POST['face'];
$e = $_POST['emotion'];

if($face && $e){

	$e = encodeEmotion($e);
	$time = time();
	
	base64_to_jpeg($face, "./images/" . $time . $e . ".jpg");
	
} else {
	echo "No compatible data received.";
}




?>