#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*fopen_s(&pf, "Текст.txt", "w");*/
	int simblol=0;
	int ridock = 0;
	int tholosni = 0;
	int prigolosni = 0;
	int chefra = 0;
  FILE * pf, * pf1;
  fopen_s(&pf, "Текст.txt","r");
  if (pf != nullptr) {
	  cout << "Фаил открыл"<<endl;
	  
	  char ch;
	  while ((ch=fgetc(pf))!=EOF)
	  {
		  cout << ch;
		  simblol++;
		  if (ch == '.' || ch == '!' || ch == '?' || ch == ',')
			  ridock++;
		  if (ch == 'а' || ch == 'я' || ch == 'у' || ch == 'ю' || ch == 'o' || ch == 'е' || ch == 'ё' || ch == 'э' || ch == 'и' || ch == 'ы')
			  tholosni++;
		  if (ch == 'б' || ch == 'в' || ch == 'г' || ch == 'д' || ch == 'ж' || ch == 'з' || ch == 'й' || ch == 'к' || ch == 'л' || ch == 'м' || ch == 'н' || ch == 'п' || ch == 'р' || ch == 'с' || ch == 'т' || ch == 'ф' || ch == 'х' || ch == 'ц' || ch == 'ч' || ch == 'ш' || ch == 'щ')
			  prigolosni++;
		   if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
			  chefra++;
	  }

	  cout<< endl;
	  fclose(pf);
	/*  Regult.txt*/

	  cout << "Фаил закрыл фаил"<<endl;
	  cout << "результат работы:" << endl;
	  cout << "Кількість символів " << simblol << endl;
	  cout << "Кількість рядків " << ridock << endl;
	  cout << "Кількість голосних " << tholosni << endl;
	  cout << "Кількість приголосних " << prigolosni << endl;
	  cout << "Кількість цифр " << chefra << endl;

	  fopen_s(&pf1, "Regult.txt", "w");
	  if (pf1 != nullptr) {
		  cout << "Фаил открыл для записи" << endl;

		  cout << "Фаил записаны значения успешно!" << endl;
		  char str[10];
		  _itoa_s(simblol, str, 10);
		  fputs(str, pf1);
		  fputs("\n", pf1);

		  _itoa_s(ridock, str, 10);
		  fputs(str, pf1);
		  fputs("\n", pf1);

		  _itoa_s(tholosni, str, 10);
		  fputs(str, pf1);
		  fputs("\n", pf1);

		  _itoa_s(prigolosni, str, 10);
		  fputs(str, pf1);
		  fputs("\n", pf1);

		  _itoa_s(chefra, str, 10);
		  fputs(str, pf1);

		  fclose(pf1);
	  }else
	  {
		  cout << "error";
	  }
  }
  else {
	  cout << "error";
  }

}

