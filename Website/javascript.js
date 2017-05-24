	var gameTitle;
	var price;
	
	function readData()
	{
		priceCheck();
		var firstName = document.getElementById('fname').value;
		var lastName = document.getElementById('lname').value;
		var postAddress = document.getElementById('address').value;
		var citySuburb = document.getElementById('cityorsuburb').value;
		var state = document.getElementById('stateSelection').value;
		var postCode = document.getElementById('postcode').value;
		var cardNumber = document.getElementById('ccardno').value;
		var cardExpiry = document.getElementById('ccardexpiry').value;
		
		
		
		alert (" First Name: " + firstName + "\n Last Name: " + lastName + "\n Postal Address: " 
				+ postAddress + "\n City/Suburb: " + citySuburb + "\n State: " + state + "\n Postcode: " 
				+ postCode +"\n Credit Card Number: " + cardNumber + "\n Credit Card Expiry Number: " + 
				cardExpiry + "\n Game Selected: " + gameTitle + "\n And this will cost $" + price + ".");
	}

	function priceCheck()
	{
	
		var title = getUrlParameter("title");
		
		if (title == "CSGO")
		{
			gameTitle = " Counter Strike, Global Offensive ";
			price = 15;
		}
		
		if (title == "Rust")
		{
			gameTitle = "Rust";
			price = 20;
		}
		
		if (title == "Fallout4")
		{
			gameTitle = "Fallout 4";
			price = 35.65;
		}
	}
	
	var getUrlParameter = function getUrlParameter(sParam) 
	{
	var URL = decodeURIComponent(window.location.search.substring(1)),
	URLVariables = URL.split('&'),
	parameterTitle,
	i;

		for (i = 0; i < URLVariables.length; i++) 
		{
			parameterTitle = URLVariables[i].split('=');

			if (parameterTitle[0] === sParam) 
			{
			return parameterTitle[1] === undefined ? true : parameterTitle[1];
			}
		}
	};