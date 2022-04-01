#include"Header.h"
using namespace std;

choice s;
enum ErrorStatusCode { NotFound = 404, FileError = 505 };


char icon0 = 2;
char icon1 = 16;
char icon2 = 17;
char icon3 = 4;
char icon4 = 2;
char icon5 = 240;



void ChoosePanel();
void UserPanel();
void AdminPanel();


class AllIngredientToAddToPrice {
	double price;
public:
	AllIngredientToAddToPrice(double price) : price(price) {}

	double operator()(double number) {
		return number + price;
	}
};


class Stock {
public:
	double cemipullar, pricecadd, ingredientsprice[6];
	int total, choice[6], tomatocount, cheesecount, onioncount, olivecount, sausagecount, mealcount;

	Stock() : tomatocount(), cheesecount(), onioncount(), olivecount(), sausagecount(), mealcount(), pricecadd(), cemipullar(), total(), choice()
	{
		for (size_t i = 0; i < 6; i++)
		{
			ingredientsprice[i] = 0;
		}
	}

	void WriteIngredientToFile()
	{
		ofstream MeFile("Ingredients.txt", ios_base::out);

		if (MeFile.is_open())
		{
			MeFile << tomatocount << endl;
			MeFile << cheesecount << endl;
			MeFile << onioncount << endl;
			MeFile << olivecount << endl;
			MeFile << sausagecount << endl;
			MeFile << mealcount << endl;
		}

		else
		{
			throw FileError;
		}

		MeFile.close();
	}

	void WriteIngredientPriceToFile()
	{
		ofstream MeFile("IngredientsPrice.txt", ios_base::out);

		if (MeFile.is_open())
		{
			for (size_t i = 0; i < 6; i++)
			{
				MeFile << ingredientsprice[i] << endl;
			}
		}

		else
		{
			throw FileError;
		}

		MeFile.close();
	}

	void WriteAdminMoneyToFile()
	{
		ofstream myfile("AdminMoney.txt", ios_base::out);

		if (myfile.is_open())
		{
			myfile << cemipullar;
		}

		else
		{
			throw FileError;
		}

		myfile.close();
	}


	void show()
	{
		system("cls");

		Ingredients();

		cout << "\t\t\t\t     -----------------------------------------------" << endl;
		cout << "\t\t\t\t     |                   INGREDIENTS               |" << endl;
		cout << "\t\t\t\t     -----------------------------------------------\n" << endl;

		ifstream AdminFile("AdminMoney.txt");

		if (AdminFile.is_open())
		{
			AdminFile >> cemipullar;
			cout << "\t\t\t\t\t\t     Current Money: " << cemipullar << endl;
		}
		else
		{
			throw FileError;
		}
		AdminFile.close();



		cout << " ------------------------------------------" << endl;
		cout << " |     Ingredients    |  Count  |  Price  |" << endl;
		cout << " ------------------------------------------" << endl;


		cout << left;
		ifstream file("Ingredients.txt");
		ifstream file2("IngredientsPrice.txt");

		if (file.is_open() && file2.is_open())
		{
			file >> tomatocount >> cheesecount >> onioncount >> olivecount >> sausagecount >> mealcount;
			for (size_t i = 0; i < 6; i++)
			{
				file2 >> ingredientsprice[i];
			}
			cout << setw(1) << ' ' << setw(16) << "Tomato" << setw(14) << "|" << setw(6) << tomatocount << setw(3) << "|" << " $ " << ingredientsprice[0] << endl;
			cout << setw(1) << ' ' << setw(16) << "Cheese" << setw(14) << "|" << setw(6) << cheesecount << setw(3) << "|" << " $ " << ingredientsprice[1] << endl;
			cout << setw(1) << ' ' << setw(16) << "Onion" << setw(14) << "|" << setw(6) << onioncount << setw(3) << "|" << " $ " << ingredientsprice[2] << endl;
			cout << setw(1) << ' ' << setw(16) << "Olive" << setw(14) << "|" << setw(6) << olivecount << setw(3) << "|" << " $ " << ingredientsprice[3] << endl;
			cout << setw(1) << ' ' << setw(16) << "Sausage" << setw(14) << "|" << setw(6) << sausagecount << setw(3) << "|" << " $ " << ingredientsprice[4] << endl;
			cout << setw(1) << ' ' << setw(16) << "Meal" << setw(14) << "|" << setw(6) << mealcount << setw(3) << "|" << " $ " << ingredientsprice[5] << endl << endl;
		}

		else
		{
			throw FileError;
		}

		file.close();
		cout << right;


		cout << "Back                      [0]" << endl;
		cout << "Buy Ingredients           [1]" << endl;
		cout << "Change Ingredient Price   [2]" << endl;
		cout << "Add price all Ingredients [3]" << endl << endl;

		cout << icon1 << "Enter Choose : ";
		cin >> s._c;

		system("cls");

		switch (s._c) {

		case '0':

			AdminPanel();
			break;

		case '1':

		choice:
			system("cls");
			cout << "Buy Tomato  [0]" << endl;
			cout << "Buy Cheese  [1]" << endl;
			cout << "Buy Onion   [2]" << endl;
			cout << "Buy Olive   [3]" << endl;
			cout << "Buy Sausage [4]" << endl;
			cout << "Buy Meal    [5]" << endl;


			cout << " " << icon1 << "Enter Choose : ";
			cin >> s.choose;

			if (s.choose == "0")
			{
				system("cls");
				cout << "How much tomato add your stock ?" << "\nIn Stock: " << tomatocount << " tomato" << "\nPrice:  $0.30" << endl;
				cin >> choice[0];

				if (cemipullar > choice[0] * 0.30)
				{
					system("cls");
					tomatocount += choice[0];
					cemipullar -= choice[0] * 0.30;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\tYou " << choice[0] << " tomato added" << endl;
					Sleep(5000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\You have no money" << endl;
					Sleep(5000);
					AdminPanel();
				}
			}

			else if (s.choose == "1")
			{
				system("cls");
				cout << "How much cheese do you want to add your stock ?" << "\nIn Stock: " << cheesecount << " cheese" << "\nPrice:  $0.50" << endl;
				cin >> choice[1];

				if (cemipullar > choice[1] * 0.50)
				{
					system("cls");
					cheesecount += choice[1];
					cemipullar -= choice[1] * 0.50;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\t\t\t\tYou " << choice[1] << " cheese added!" << endl;
					Sleep(5000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\tYou have no money" << endl;
					Sleep(3000);
					AdminPanel();
				}
			}

			else if (s.choose == "2")
			{
				system("cls");
				cout << "How much onion do you want to add your stock ?" << "\nIn Stock: " << onioncount << " onion" << "\nPrice:  $0.25" << endl;
				cin >> choice[2];

				if (cemipullar > choice[2] * 0.25)
				{
					system("cls");
					onioncount += choice[2];
					cemipullar -= choice[2] * 0.25;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\t\t\t\tYour " << choice[2] << " onion was added!" << endl;
					Sleep(3000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\tSorry, you have no money" << endl;
					Sleep(3000);
					AdminPanel();
				}
			}

			else if (s.choose == "3")
			{
				system("cls");
				cout << "How much olive do you want to add your stock ?" << "\nIn Stock: " << olivecount << " olive" << "\nPrice:  $0.55" << endl;
				cin >> choice[3];

				if (cemipullar > choice[3] * 0.55)
				{
					system("cls");
					olivecount += choice[3];
					cemipullar -= choice[3] * 0.55;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\t\t\t\tYour " << choice[3] << " olive was added!" << endl;
					Sleep(3000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\tSorry, you have no money" << endl;
					Sleep(3000);
					AdminPanel();
				}
			}

			else if (s.choose == "4")
			{
				system("cls");
				cout << "How much sausage do you want to add your stock ?" << "\nIn Stock: " << sausagecount << " sausage" << "\nPrice:  $2.25" << endl;
				cin >> choice[4];

				if (cemipullar > choice[4] * 2.25)
				{
					system("cls");
					sausagecount += choice[4];
					cemipullar -= choice[4] * 2.25;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\t\t\t\tYour " << choice[4] << " sausage was added!" << endl;
					Sleep(3000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\tSorry, you have no money" << endl;
					Sleep(3000);
					AdminPanel();
				}
			}

			else if (s.choose == "5")
			{
				system("cls");
				cout << "How much meal do you want to add your stock ?" << "\nIn Stock: " << mealcount << " meal" << "\nPrice:  $3.75" << endl;
				cin >> choice[5];

				if (cemipullar > choice[5] * 3.75)
				{
					system("cls");
					mealcount += choice[5];
					cemipullar -= choice[5] * 3.75;

					WriteIngredientToFile();
					WriteAdminMoneyToFile();

					cout << "\a\t\t\t\t\tYour " << choice[5] << " meal was added!" << endl;
					Sleep(3000);
					show();
				}

				else
				{
					system("cls");
					cout << "\t\t\t\t\tSorry, you have no money" << endl;
					Sleep(3000);
					AdminPanel();
				}
			}

			else
			{
				system("cls");
				cout << "\a\t\t\t\t\tWrong choice,Try again!" << endl;
				Sleep(1000);
				goto choice;
			}

			break;

		case '2':

		choice2:
			system("cls");
			cout << "Change Tomato Price  [0]" << endl;
			cout << "Change Cheese Price  [1]" << endl;
			cout << "Change Onion Price   [2]" << endl;
			cout << "Change Olive Price   [3]" << endl;
			cout << "Change Sausage Price [4]" << endl;
			cout << "Change Meal Price    [5]" << endl;


			cout << " " << icon1 << " Please Enter your Choose: ";
			cin >> s.choose;

			if (s.choose == "0")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[0] << " $" << endl;
				cout << " " << icon1 << "Enter new Tomato Price: ";
				cin >> ingredientsprice[0];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tTomato price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else if (s.choose == "1")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[1] << " $" << endl;
				cout << " " << icon1 << "Enter new Cheese Price: ";
				cin >> ingredientsprice[1];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tCheese price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else if (s.choose == "2")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[2] << " $" << endl;
				cout << " " << icon1 << "Enter new Onion Price: ";
				cin >> ingredientsprice[2];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tOnion price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else if (s.choose == "3")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[3] << " $" << endl;
				cout << " " << icon1 << "Enter new Olive Price: ";
				cin >> ingredientsprice[3];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tOlive price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else if (s.choose == "4")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[4] << " $" << endl;
				cout << " " << icon1 << "Enter new Sausage Price: ";
				cin >> ingredientsprice[4];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tSausage price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else if (s.choose == "5")
			{
				system("cls");
				cout << "Old Price: " << ingredientsprice[5] << " $" << endl;
				cout << " " << icon1 << "Enter new Meal Price: ";
				cin >> ingredientsprice[5];

				WriteIngredientPriceToFile();

				system("cls");
				cout << "\a\t\t\t\t\tMeal price was changed!" << endl;
				Sleep(3000);
				show();
			}

			else
			{
				system("cls");
				cout << "\a\t\t\t\t\tWrong choice,Try again!" << endl;
				Sleep(1000);
				goto choice2;
			}

			break;
		case '3':

			system("cls");
			cout << " " << icon1 << "Add price for all ingredients: ";
			cin >> pricecadd;
			transform(ingredientsprice, ingredientsprice + 6, ingredientsprice, AllIngredientToAddToPrice(pricecadd));

			WriteIngredientPriceToFile();

			system("cls");
			cout << "\a\t\t\t\t\New price was added!" << endl;
			Sleep(3000);
			show();


		default:
			system("cls");
			cout << "\a\t\t\t\t\tInvalid Input" << endl;
			Sleep(1000);
			show();
			break;

		}
		Sleep(3000);
	}
};

Stock stock;

class UserChoice {
public:
	string productname, soklar;
	int cem, choice[6];
	bool duzgunluk;
	UserChoice() : productname(), choice(), duzgunluk(), soklar(), cem() {}

	void show()
	{
		if (stock.tomatocount > 0 || stock.cheesecount > 0 || stock.onioncount > 0 || stock.olivecount > 0 || stock.sausagecount > 0 || stock.mealcount > 0)
		{
			system("cls");
			cout << " " << icon1 << " Enter product name: ";
			cin.ignore();
			getline(cin, productname);
			cout << "\t\t\t\t\tAdd ingredient for " << productname << endl;

		tomato:
			system("cls");
			cout << " " << icon1 << "How much tomato do you want to add your " << productname << "?" << "\nIn Stock: " << stock.tomatocount << "\nPrice: " << stock.ingredientsprice[0] << "$" << endl;
			cin >> choice[0];
			if (choice[0] > stock.tomatocount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much tomato" << endl;
				Sleep(3000);
				goto tomato;
			}

		cheese:
			system("cls");
			cout << " " << icon1 << "How much cheese do you want to add your " << productname << "?" << "\nIn Stock: " << stock.cheesecount << "\nPrice: " << stock.ingredientsprice[1] << "$" << endl;
			cin >> choice[1];
			if (choice[1] > stock.cheesecount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much cheese" << endl;
				Sleep(3000);
				goto cheese;
			}

		onion:
			system("cls");
			cout << " " << icon1 << "How much onion do you want to add your " << productname << "?" << "\nIn Stock: " << stock.onioncount << "\nPrice: " << stock.ingredientsprice[2] << "$" << endl;
			cin >> choice[2];
			if (choice[2] > stock.onioncount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much onion" << endl;
				Sleep(3000);
				goto onion;
			}

		olive:
			system("cls");
			cout << " " << icon1 << "How much olive do you want to add your " << productname << "?" << "\nIn Stock: " << stock.olivecount << "\nPrice: " << stock.ingredientsprice[3] << "$" << endl;
			cin >> choice[3];
			if (choice[3] > stock.olivecount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much olive" << endl;
				Sleep(3000);
				goto olive;
			}

		sausage:
			system("cls");
			cout << " " << icon1 << "How much sausage do you want to add your " << productname << "?" << "\nIn Stock: " << stock.sausagecount << "\nPrice: " << stock.ingredientsprice[4] << "$" << endl;
			cin >> choice[4];
			if (choice[4] > stock.sausagecount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much sausage" << endl;
				Sleep(3000);
				goto sausage;
			}


		meal:
			system("cls");
			cout << " " << icon1 << "How much meal do you want to add your " << productname << "?" << "\nIn Stock: " << stock.mealcount << "\nPrice: " << stock.ingredientsprice[5] << "$" << endl;
			cin >> choice[5];
			if (choice[5] > stock.mealcount)
			{
				system("cls");
				cout << "\t\t\t\t\tSorry in stock not much meal" << endl;
				Sleep(3000);
				goto meal;
			}

			duzgunluk = true;

			cem = (choice[0] * stock.ingredientsprice[0]) + (choice[1] * stock.ingredientsprice[1]) + (choice[2] * stock.ingredientsprice[2]) + (choice[3] * stock.ingredientsprice[3]) + (choice[4] * stock.ingredientsprice[4]) + (choice[5] * stock.ingredientsprice[5]);
			stock.tomatocount -= choice[0];
			stock.cheesecount -= choice[1];
			stock.onioncount -= choice[2];
			stock.olivecount -= choice[3];
			stock.sausagecount -= choice[4];
			stock.mealcount -= choice[5];

			stock.WriteIngredientToFile();

			system("cls");
			cout << "\a\t\t\t\t\tYour ingredient was added!" << endl;
			Sleep(3000);

		}
		else
		{
			system("cls");
			cout << "\a\t\t\t\t\tSorry, there are no ingredients in stock" << endl;
			Sleep(3000);
			UserPanel();
		}
	}
};

namespace ADMIN {
	string time = __TIME__;
	class emp
	{
	public:
		double pprice;
		int id_dxl, id;
		string name, ingredientname, kkal;

		emp() : name(), pprice(), id(), id_dxl(), ingredientname(), kkal() {}

		void empdata()
		{
			ofstream myfile("Menu.txt", ios_base::out);

			if (myfile.is_open())
			{
				system("cls");
				cout << "Enter data of product " << 1 << endl << endl;
				id = 1;
				cout << " " << icon1 << " Enter product name: ";
				cin.ignore();
				getline(cin, name);

				cout << " " << icon1 << " Product Price: ";
				cin >> pprice;

				cout << "\nAdd the ingredients, separate the ingredients with a comma and write down the total calories" << endl << endl;
				cout << " " << icon1 << " Add ingredient for " << name << " : ";
				cin.ignore();
				getline(cin, ingredientname);

				cout << " " << icon1 << " Add total kkal for " << ingredientname << " : ";
				cin >> kkal;

				myfile << id << endl;
				myfile << name << endl;
				myfile << pprice << endl;
				myfile << ingredientname << endl;
				myfile << kkal << endl;
			}

			else
			{
				throw FileError;
			}

			myfile.close();
		}

		void search()
		{
			ifstream file("Menu.txt");
			if (file.is_open())
			{
				Search();

				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << "\t\t\t\t     |                 SEARCH PRODUCTS             |" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl;
				cout << " " << icon1 << " Enter id of product which you want to search: ";

				cin >> id_dxl;

				file >> id >> name >> pprice >> ingredientname >> kkal;

				if (id_dxl == id)
				{
					system("cls");
					cout << "Data of product " << 1 << endl;

					cout << "Product Name: " << name << endl;

					cout << "Product Price: " << pprice << " $ " << endl;

					cout << "Product Read Time: " << time << endl;

					cout << "Ingredient of " << name << " : " << ingredientname << endl;

					cout << "Total kkal of " << name << " : " << kkal << endl;

					cout << endl << endl;
					Sleep(3000);

				}

				else
				{
					system("cls");
					cout << "\a\t\t\t\tNo such data found" << endl;
					Sleep(2000);
				}

				Sleep(3000);
			}

			else
			{
				system("cls");
				cout << "\t\t\t\tNo data is entered" << endl;
				Sleep(2000);
			}

			file.close();
		}

		void update()
		{
			ofstream myfile("Menu.txt", ios_base::out);

			if (myfile.is_open())
			{
				system("cls");

				Update();

				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << "\t\t\t\t     |                 UPDATE PRODUCT              |" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl << endl;
				cout << " " << icon1 << " Enter id of product id which you want to update: ";

				cin >> id_dxl;

				if (id_dxl == id)
				{
					system("cls");
					cout << "Old data of product " << 1 << endl;

					cout << "Product Name: " << name << endl;

					cout << "Product Price: " << pprice << " $ " << endl;

					cout << "Ingredient of " << name << " : " << ingredientname << endl;

					cout << "Total kkal of " << name << " : " << kkal << endl << endl << endl;

					cout << "\t\t\t\t\tEnter new data" << endl;

					cout << " " << icon1 << " Enter product name: ";
					cin.ignore();
					getline(cin, name);

					cout << " " << icon1 << " Enter Product Price: ";

					cin >> pprice;

					cout << " " << icon1 << " Add ingredient for " << name << " : ";
					cin.ignore();
					getline(cin, ingredientname);

					cout << " " << icon1 << " Add total kkal for " << ingredientname << " : ";
					cin >> kkal;

					myfile << id << endl;
					myfile << name << endl;
					myfile << pprice << endl;
					myfile << ingredientname << endl;
					myfile << kkal << endl;

				}

				else
				{
					system("cls");
					cout << "\a\t\t\t\tNo such data found" << endl;
					Sleep(2000);
				}
			}

			else
			{
				system("cls");
				cout << "\t\t\t\tNo data is entered" << endl;
				Sleep(2000);
			}

			myfile.close();
		}

		void del()
		{
			ifstream file("Menu.txt");

			if (file.is_open())
			{
				system("cls");
				ofstream myfile("Menu.txt", ios_base::out);
				myfile << NULL;
				cout << "\t\t##################################  All data is deleted  ##################################" << endl;
				Sleep(1000);
			}

			else
			{
				system("cls");
				cout << "\t\t\t\tNo data is entered" << endl;
				Sleep(2000);
			}

			file.close();

		}

		void show() {

			ifstream file("Menu.txt");

			if (file.is_open())
			{
				Product();

				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << "\t\t\t\t     |                 ALL PRODUCTS                |" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl;
				file >> id >> name >> pprice >> ingredientname >> kkal;

				cout << "Product Name: " << name << endl;

				cout << "Price: " << pprice << " $ " << endl;

				cout << "Product Read Time: " << time << endl;

				cout << "Ingredient of " << name << " : " << ingredientname << endl;

				cout << "Total kkal of " << name << " : " << kkal << endl;
				cout << endl << endl;
			}

			else
			{
				system("cls");
				cout << "\t\t\t\tNo data is entered" << endl;
			}

			file.close();
			Sleep(5000);
		}

		void statikler()
		{
			ifstream adminfile("AdminMoney.txt");
			system("cls");
			if (adminfile.is_open())
			{
				Statics();

				adminfile >> stock.cemipullar;
				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << "\t\t\t\t     |                 ALL STATICS                 |" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl;

				cout << "\t\t\t\t     All day earnings: " << stock.cemipullar << " $" << endl;
				cout << "\t\t\t\t     Today's earnings: " << stock.total << " $" << endl;
			}

			else
			{
				throw FileError;
			}

			adminfile.close();
			Sleep(3000);
		}
	};

}

ADMIN::emp e;
UserChoice uc;

class Admin {
public:
	string AdminUsername, AdminPassword;

	Admin() = default;

	Admin(const string& AdminUsername, const string& AdminPassword) : AdminUsername(AdminUsername), AdminPassword(AdminPassword) {}

	void show() {
		if (AdminUsername == "admin" && AdminPassword == "admin")
		{
			system("cls");
			while (1)
			{
				system("cls");

				Panel();

				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << "\t\t\t\t     |                  Admin Panel                |" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl << endl << endl;

				cout << "\t\t\t\t\t\tPress 1 to enter product" << endl;

				cout << "\t\t\t\t\t\tPress 2 to show product" << endl;

				cout << "\t\t\t\t\t\tPress 3 to search product" << endl;

				cout << "\t\t\t\t\t\tPress 4 to update product" << endl;

				cout << "\t\t\t\t\t\tPress 5 to delete product" << endl;

				cout << "\t\t\t\t\t\tPress 6 to see static's" << endl;

				cout << "\t\t\t\t\t\tPress 7 to see ingredients" << endl;

				cout << "\t\t\t\t\t\tPress 8 to exit" << endl;

				cout << "\n\n " << icon1 << " Enter number: ";
				cin >> s._c;

				system("cls");

				switch (s._c) {

				case '1':

					e.empdata();

					break;

				case '2':

					e.show();

					break;

				case '3':

					e.search();

					break;

				case '4':

					e.update();

					break;

				case '5':

					e.del();

					break;

				case '6':

					e.statikler();

					break;

				case '7':

					stock.show();

					break;

				case '8':

					UserPanel();

					break;

				default:

					cout << "\a\t\t\t\t\tInvalid Input" << endl;
					Sleep(3000);
					break;

				}

			}
		}
		else
		{
			system("cls");
			cout << "Parol ve ya Username sefhdir, Admin Sehifesi Bloklandi, Bir daha sinayin!\n\n";
			throw NotFound;
		}
	}


};

class Client {
public:
	double vat;
	int id, pay, change, drinks, totalorder, quantity;
	char ordercode;
	string UserName, totaldrinks;

	Client() : id(), vat(), ordercode(), drinks(), quantity(), pay(), change(), totalorder(), totaldrinks() {}

	void show()
	{
		ifstream file("Menu.txt");
		file >> e.id;
	userchoice:
		if (UserName != "\0" && uc.duzgunluk == false)
		{
		baslangic2:
			cout << endl;
			system("cls");

			TheMenuWrite();

			if (e.id != 0)
			{
				while (!file.eof())
				{
					file >> e.name >> e.pprice >> e.ingredientname >> e.kkal;
				}
				cout << "\t\t\t| " << 1 << ") " << e.name << endl;
			}

			cout << "\t\t\t| 20) Select your own menu" << endl;
			cout << "\t\t\t|" << endl;
			cout << "\t\t\t| 0) Exit Program" << endl;
			cout << "\t\t\t| 192) Admin Panel" << endl;
			cout << "\t\t\t| -----------------------------" << endl;
			cout << "\t\t\t* -----------------------------\n\n\n\n\n\n" << endl;

			cout << " " << icon1 << " Please Enter your Choose: ";

			cin >> id;

			if (id == 20)
			{
				uc.show();
				goto userchoice;
			}

			else if (id == 0)
			{
				system("cls");
				exit(0);
			}

			else if (id == 192)
			{
				AdminPanel();
			}

			if (id == e.id)
			{
				system("cls");
				cout << endl;
				cout << "\t\t\t\t     -----------------------------------------------" << endl;
				cout << setw(58) << e.name << " - MENU" << endl;
				cout << "\t\t\t\t     -----------------------------------------------\n" << endl;

				cout << endl;
				cout << "\t+-----------------------------------------------  Menu #" << id << "  -----------------------------------------------+" << endl;
				cout << "\t|\t\t\t\t\tHer menuya Pulsuz icki verilir" << endl;
				cout << "\t|" << endl;
				cout << "\t|   Ingredient of " << e.name << " : " << e.ingredientname << endl;
				cout << "\t|   Total Kkal: " << e.kkal << endl;
				cout << "\t|" << endl;
				cout << "\t|\t\t\t\t\t\tPrice: " << e.pprice << "$" << endl;
				cout << "\t+---------------------------------------------------------------------------------------------------------+" << endl;

				cout << " " << icon1 << "If you want this menu press [1]  If you don't want this menu press [0]: ";

				cin >> ordercode;
			}

			else
			{
				system("cls");
				cout << "\a\t\t\t\t\tWrong choice, choose again.\n\n";
				Sleep(3000);
				goto baslangic2;
			}

			if (ordercode == '1')
			{
				system("cls");
				cout << "\n\n                             " << icon5 << " Choice of Drink: " << icon5 << "\n";
				cout << "\n\t\t\t + ------------------------ +" << endl;
				cout << "\t\t\t |          DRINKS " << icon3 << "        |" << endl;
				cout << "\t\t\t |                          |" << endl;
				cout << "\t\t\t |     1)    COLA           |" << endl;
				cout << "\t\t\t |     2)    SPRITE         |" << endl;
				cout << "\t\t\t |     3)    FANTA          |" << endl;
				cout << "\t\t\t |     4)    REDBULL        |" << endl;
				cout << "\t\t\t |   5) I don't want drink  |" << endl;
				cout << "\t\t\t + ------------------------ +\n" << endl;


				cout << " " << icon1 << " Please Choose Drinks: ";
				cin >> drinks;

				switch (drinks)
				{
				case 1:
					totaldrinks = "  COLA  ";
					break;

				case 2:
					totaldrinks = "  SPRITE  ";
					break;

				case 3:
					totaldrinks = "  FANTA   ";
					break;

				case 4:
					totaldrinks = "  REDBULL  ";
					break;

				case 5:
					totaldrinks = " NO DRINK ";
					break;

				default:
					cout << " Wrong Input, Written as NO DRINK  \n\n";
					totaldrinks = " NO DRINK ";
					break;
				}

			}

			else
			{
				system("cls");
				cout << "\t\t\t\t\tYou left the menu, choose again.\n\n";
				Sleep(3000);
				goto baslangic2;
			}

			cout << "\n" << " " << icon1 << " Please Enter Quantity: ";
			cin >> quantity;

			totalorder = e.pprice * quantity;

			cout << "\n\n";

			system("cls");
			cout << "\t\t\t\tGenerating your Bill ";

			for (int a = 1; a <= 3; a++)
			{
				Sleep(900);
				cout << "...";
			}


			cout << "\n\n\n";
			stock.total = 0;
			system("cls");

			cout << "                                ELOVSET DAYI RESTAURANT " << icon0 << "\n";
			cout << "                                   28 May Kucesi, Baki \n";
			cout << "                                      24 saat acik\n";
			cout << "                        +++++++++++++++++++++++++++++++++++++++\n\n\n";


			cout << "  Cashier  : QAFAR\n";
			cout << "  Customer : " << UserName;


			cout << "\n\n\n  You have ordered: " << setw(30) << "Transaction #1" << "\n";
			cout << " ------------------------------------------------------------------------------\n";
			cout << "              ITEM\t        |  DRINKS  | UNIT PRICE |  QUANTITY  | AMOUNT\n";
			cout << " ------------------------------------------------------------------------------\n";


			cout << "\t" << e.name << "\t\t\t | " << totaldrinks << " | \t" << e.pprice << " | \t" << quantity << " |\t  $ " << totalorder << endl;

			cout << " ------------------------------------------------------------------------------\n" << endl;

			stock.total = stock.total + totalorder;

			do
			{
				cout << "                                                           Total: $ " << stock.total << "\n";
				cout << "  Enter Received cash : ";
				cin >> pay;

				if (pay < stock.total)
				{
					cout << "\n" << " ------------------------------------------------------------------------------\n";
					cout << "                        Please do not deceive us -_- ";
					cout << "\n" << " ------------------------------------------------------------------------------\n";
				}

				else
				{
					change = pay - stock.total;
					cout << "  Changed Due         : " << change << "\n";
					cout << "  Items Purchased     : " << 1;

					vat = stock.total * 0.18;
					cout << " \n  18% VAT Included    : " << vat;



				}

			} while (pay < stock.total);

			Sleep(3000);
			system("cls");
			cout << "\t\t\t\t\tThank you, Come again " << icon4 << endl << endl;

			ofstream myfile("AdminMoney.txt", ios_base::out);

			if (myfile.is_open())
			{
				stock.cemipullar += stock.total;
				myfile << stock.cemipullar;
			}

			else
			{
				throw FileError;
			}

			myfile.close();
			file.close();
			Sleep(2000);
			UserPanel();
		}

		else if (uc.duzgunluk == true)
		{
			system("cls");
			cout << "\n\n                             " << icon5 << " Choice of Drink: " << icon5 << "\n";
			cout << "\n\t\t\t + ------------------------ +" << endl;
			cout << "\t\t\t |          DRINKS " << icon3 << "        |" << endl;
			cout << "\t\t\t |                          |" << endl;
			cout << "\t\t\t |     1)    COLA           |" << endl;
			cout << "\t\t\t |     2)    SPRITE         |" << endl;
			cout << "\t\t\t |     3)    FANTA          |" << endl;
			cout << "\t\t\t |     4)    REDBULL        |" << endl;
			cout << "\t\t\t |   5) I don't want drink  |" << endl;
			cout << "\t\t\t + ------------------------ +\n" << endl;


			cout << " " << icon1 << " Please Choose Drinks: ";
			cin >> drinks;

			switch (drinks)
			{
			case 1:
				uc.soklar = "  COCA  ";
				break;

			case 2:
				uc.soklar = "  SPRITE  ";
				break;

			case 3:
				uc.soklar = "  FANTA   ";
				break;

			case 4:
				uc.soklar = "  REDBULL  ";
				break;

			case 5:
				uc.soklar = " NO DRINK ";
				break;

			default:
				cout << " Wrong Input, Written as NO DRINK  \n\n";
				uc.soklar = " NO DRINK ";
				break;
			}
			cout << "\n\n";

			system("cls");
			cout << "\t\t\t\tGenerating your Bill ";

			for (int a = 1; a <= 3; a++)
			{
				Sleep(900);
				cout << "...";
			}

			cout << "\n\n\n";
			stock.total = 0;
			system("cls");


			cout << "                                ELOVSET DAYI RESTAURANT " << icon0 << "\n";



			cout << "  Cashier  : QAFAR\n";
			cout << "  Customer : " << UserName;

			cout << "\n\n\n  You have ordered: " << setw(30) << "Transaction #1" << "\n";
			cout << " ------------------------------------------------------------------------------\n";
			cout << "              ITEM\t        |  DRINKS  |  QUANTITY  | AMOUNT\n";
			cout << " ------------------------------------------------------------------------------\n";

			cout << "\t  " << uc.productname << "\t\t | " << uc.soklar << " | \t" << 1 << " |\t  $ " << uc.cem << endl;

			cout << " ------------------------------------------------------------------------------\n" << endl << endl;

			cout << " ------------------------------------------\n";
			cout << " |     Ingredients    |  Count  |  Price  |\n";
			cout << " ------------------------------------------\n";


			cout << left;
			cout << setw(8) << ' ' << setw(14) << "Tomato" << setw(4) << "|" << setw(6) << uc.choice[0] << setw(3) << "|" << " $ " << uc.choice[0] * stock.ingredientsprice[0] << endl;
			cout << setw(8) << ' ' << setw(14) << "Cheese" << setw(4) << "|" << setw(6) << uc.choice[1] << setw(3) << "|" << " $ " << uc.choice[1] * stock.ingredientsprice[1] << endl;
			cout << setw(8) << ' ' << setw(14) << "Onion" << setw(4) << "|" << setw(6) << uc.choice[2] << setw(3) << "|" << " $ " << uc.choice[2] * stock.ingredientsprice[2] << endl;
			cout << setw(8) << ' ' << setw(14) << "Olive" << setw(4) << "|" << setw(6) << uc.choice[3] << setw(3) << "|" << " $ " << uc.choice[3] * stock.ingredientsprice[3] << endl;
			cout << setw(8) << ' ' << setw(14) << "Sausage" << setw(4) << "|" << setw(6) << uc.choice[4] << setw(3) << "|" << " $ " << uc.choice[4] * stock.ingredientsprice[4] << endl;
			cout << setw(8) << ' ' << setw(14) << "Meal" << setw(4) << "|" << setw(6) << uc.choice[5] << setw(3) << "|" << " $ " << uc.choice[5] * stock.ingredientsprice[5] << endl << endl;
			cout << right;

			stock.total = stock.total + uc.cem;

			do
			{
				cout << "                                                           Total: $ " << stock.total << "\n";
				cout << "  Enter Received cash : ";
				cin >> pay;


				if (pay < stock.total)
				{
					cout << "\n" << " ------------------------------------------------------------------------------\n";
					cout << "                        Please do not deceive us -_- ";
					cout << "\n" << " ------------------------------------------------------------------------------\n";
				}


				else {

					change = pay - stock.total;
					cout << "  Changed Due         : " << change << "\n";
					cout << "  Items Purchased     : " << 1;

					vat = stock.total * 0.18;
					cout << " \n  18% VAT Included    : " << vat;


					cout << "\n\n";
					cout << "                          This serves as your Official Receipt.\n";
					cout << "                           Thank you, and please come again.\n";
					cout << "                          Visit us also at bothdeveloper.unaux.com\n\n\n";

				}

			} while (pay < stock.total);

			Sleep(3000);
			system("cls");

			cout << "\t\t\t\t\tThank you, Come again " << icon4 << endl << endl;

			ofstream myfile("AdminMoney.txt", ios_base::out);

			if (myfile.is_open())
			{
				stock.cemipullar += stock.total;
				myfile << stock.cemipullar;
			}

			else
			{
				throw FileError;
			}

			myfile.close();

			Sleep(2000);
			uc.duzgunluk = 0;
			UserPanel();
		}
	}
};

void AdminPanel()
{
	Admin a;
	system("cls");
	color(hConsole, 6);

	TheMenuWrite();

	cout << "\n\n";
	cout << "\t\t\t-------------------------\n\n";
	cout << "\t\t\t       Admin Login" << "\n";
	cout << "\t\t\t-------------------------\n\n\n\n";


	cout << "\t\t\tUsername: ";
	cin >> a.AdminUsername;
	cout << endl << endl;
	cout << "\t\t\tPassword: ";
	s._c = _getch();

	while (s._c != 13)
	{
		a.AdminPassword.push_back(s._c);
		cout << '*';
		s._c = _getch();
	}

	a.show();
}

void UserPanel()
{
	Client c;
	system("cls");
	color(hConsole, 10);

	ifstream file("Ingredients.txt");
	ifstream file2("IngredientsPrice.txt");

	file >> stock.tomatocount >> stock.cheesecount >> stock.onioncount >> stock.olivecount >> stock.sausagecount >> stock.mealcount;

	for (size_t i = 0; i < 6; i++)
	{
		file2 >> stock.ingredientsprice[i];
	}

	system("cls");

	TheMenuWrite();

	cout << "\n\n";
	cout << "\t\t\t-------------------------\n\n";
	cout << "\t\t\t       Client Login" << "\n";
	cout << "\t\t\t-------------------------\n\n\n\n";


	cout << "\t\t\tEnter your name: ";
	cin >> c.UserName;

	c.show();
}

void ChoosePanel()
{
	system("cls");
	color(hConsole, 176);

	TheMenuWrite();

	cout << "\n\n";
	cout << "\t\t\t-------------------------\n";
	cout << "\t\t\t      [1]Admin Login     " << "\n";
	cout << "\t\t\t      [2]Users Login    " << "\n";
	cout << "\t\t\t-------------------------\n\n\n\n";


	cout << "\tEnter number: ";
	cin >> s._dxl;
}

int main()
{
	Loading();

	s._check++;
	if (s._check >= 1)
		FirstPage();


start:
	ChoosePanel();
	if (s._dxl == "1")
	{
		color(hConsole, 6);

		AdminPanel();
	}

	else if (s._dxl == "2")
	{
		color(hConsole, 10);
		UserPanel();
	}

	else
	{
		system("cls");
		color(hConsole, 4);
		cout << "\a\t\t\t\t\t    Wrong choice,Try again!   " << endl;
		Sleep(2000);
		goto start;
	}
}