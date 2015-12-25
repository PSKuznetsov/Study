using System;
using Parse;
using System.Diagnostics;
using System.Collections;
using System.Threading;
using System.Threading.Tasks;


namespace ClientServerCL
{
	public class User
	{

		public UInt64 cardNumber {set; get;}
		public string firstName {set; get;}
		public string lastName {set; get;}
		public string address {set; get;}
		public string userName {set; get;}
		public string password {set; get;}
		public string email {set; get;}

		public User ()
		{
			
		}

		public async Task<bool> signUpWithPrivacy() {
			if (firstName != null && lastName != null && userName != null && password != null && email != null) {
				
				var newUser = new ParseUser() {

					Username = userName,
					Password = password,
					Email    = email
				};

				newUser["firstName"]  = firstName;
				newUser["lastName"]   = lastName;
				newUser["address"]    = address;
				newUser["cardNumber"] = cardNumber;

				Console.WriteLine("Start authentication!\n");

				try {
					await newUser.SignUpAsync();
					Console.WriteLine("User is sign up!\n");
					return true;
				}
				catch (Exception e) {
					Console.WriteLine(e.ToString());
					return false;
				}

			}
			return false;
		}

		public async Task<bool> signInWithPrivacy() {
			if (userName != null && password != null) {
			Console.WriteLine("Starting Authentication!");
				try {
    				await ParseUser.LogInAsync(userName, password);
    				return true;
				}
				catch (Exception e) {
					Console.WriteLine(e.Message);
					return false;
				}
			}

			return false;
		}

		public void logOut() {
			try {
				ParseUser.LogOut();
			}
			catch (Exception e) {
				Console.WriteLine("{0}", e.ToString());
			}

		}

		public bool IsUserLoggedIn () {
  			if (ParseUser.CurrentUser != null) {
    			return true;
  			}
  			else {
    			return false;
  			}
		}

	}
}

