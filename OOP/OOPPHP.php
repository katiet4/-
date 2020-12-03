<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>


	<?php
	interface Password
	{
		
		function generate_password($length);
	}

	class Lvl_1 extends Password
	{
		private $password;
		function password_get()
		{
			return $this->$password;
		}
		function generate_password($length)
		{
			$symbols = 'qwertyuiopasdfghjklzxcvbnm';
			$result = "";
			for ($i = 0; $i < $length; $i++) { 
				$result .= $symbols[rand(0,strlen($symbols))];
			}
			$this->$password = $result;
		}

	}
	class Lvl_2 extends Password
	{
		private $password;
		function password_get()
		{
			return $this->$password;
		}
		function generate_password($length)
		{
			$symbols = 'qwertyuiopasdfghjklzxcvbnm1234567890';
			$result = "";
			for ($i = 0; $i < $length; $i++) { 
				$result .= $symbols[rand(0,strlen($symbols))];
			}
			$this->$password = $result;
		}
	}
	class Lvl_3 extends Password
	{
		private $password;
		function password_get()
		{
			return $this->$password;
		}
		function generate_password($length)
		{
			$symbols = 'qwertyuiopasdfghjklzxcvbnm1234567890()_+{}?><*&^%$#@!';
			$result = "";
			for ($i = 0; $i < $length; $i++) { 
				$result .= $symbols[rand(0,strlen($symbols))];
			}
			$this->$password = $result;
		}
	}
	class Lvl_4 extends Password
	{
		private $password;
		function password_get()
		{
			return $this->$password;
		}
		function generate_password($length)
		{
			$symbols = 'qwertyuiopasdfghjklzxcvbnm1234567890()_+{}?><*&^%$#@!QWERTYUIOPASDFGHJKLZXCVBNM';
			$result = "";
			for ($i = 0; $i < $length; $i++) { 
				$result .= $symbols[rand(0,strlen($symbols))];
			}
			$this->$password = $result;
		}
	}


	//	start
	if(isset($_GET["lvl"])){
		$lvls = [new Lvl_1(), new Lvl_2(), new Lvl_3(), new Lvl_4()];
		$lvls[(int)$_GET["lvl"]]->generate_password((int)$_GET["length"]);
		echo "PASSWORD: ".$lvls[(int)$_GET["lvl"]]->password_get();
	}



	?>

<form action="index.php" method="get">
	<br/><select name="lvl">
		<option value="0">1</option>
		<option value="1">2</option>
		<option value="2">3</option>
		<option value="3">4</option>
	</select><br/>
	<input type="text" name="length" placeholder="Length of password" required><br/>
	<input type="submit" name="generate" value="Generate">
</form>
</body>
</html>
