using System;
using Parse;
using System.Threading;
using System.Threading.Tasks;

namespace ClientServerCL
{
	class MainClass
	{
		public static void Main (string[] args)
		{
 
  			ParseClient.Initialize("3TnbmAsf7UxT8Dj5V1nwPClMNmf294E3FzwxC7iM", 
  									"0u165RJwssOZmZWLbtHiy4j8QXpvvGrgDMRfYAas");

  			User newUser = new User();

  			newUser.cardNumber = 1234123412341234;
  			newUser.email      = "email@mail.com";
  			newUser.firstName  = "Petya";
  			newUser.lastName   = "Ivanov";
  			newUser.address    = "Saratov, Volskaya street";
  			newUser.password   = "qwertypass";
  			newUser.userName   = "IPetya";

  		    //Task<bool> result = newUser.signUpWithPrivacy();
  		    //result.Wait();
  			Task<bool> result = newUser.signInWithPrivacy();
  			result.Wait();
  			//newUser.logOut();
  			Console.WriteLine("{0}", newUser.IsUserLoggedIn());
		}
	}
}
