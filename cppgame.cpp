
#include <iostream>

#include <time.h>

#include <Windows.h>

#include <process.h>

#include <stdlib.h>

using namespace std;

class Black;





enum Color {

	/*

	0 : 검정색, 1 : 파랑색, 2 : 초록색, 3 : 옥색

	4 : 빨간색, 5 : 자주색, 6 : 노란색, 7 : 흰색

	8 : 회색, 9 : 연한 파란색, 10 : 연한 초록색, 11 : 연한 옥색

	12 : 연한 빨간색, 13 : 연한 자주색, 14 : 연한 노란색, 15 : 진한 흰색

	*/

	BLACK, BLUE, GREEN, JADE,

	RED, PURPLE, YELLOW, WHITE,

	GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_JADE,

	LIGHT_RED, LIGHT_PURPLE, LIGHT_YELLOW, LIGHT_WHITE

};

void TextColor(int n) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);

}

void ConsoleSize() {

	system("mode con: cols=100 lines=50");

	system("pause>>null");

}

void gotoxy(int x, int y) {

	COORD Pos = { x , y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}



int Game_menu()

{

	int i;

	TextColor(6);

	gotoxy(0, 10);

	cout << "====================================================================================================" << endl;

	gotoxy(40, 11);

	cout << "Black Engineer";

	gotoxy(0, 12);

	cout << "====================================================================================================" << endl;

	gotoxy(40, 13);

	cout << "1. Attack";

	gotoxy(40, 14);

	cout << "2. Status";

	gotoxy(40, 15);

	cout << "3. Arsenal";

	gotoxy(40, 16);

	cout << "4. Buy Weapon";

	gotoxy(40, 17);

	cout << "5. Money-Making";

	gotoxy(40, 18);

	cout << "6. Research";

	gotoxy(0, 19);

	cout << "====================================================================================================";

	gotoxy(34, 21);

	cout << "어떤 작업을 실행하시겠습니까?" << endl;

	gotoxy(47, 23);

	cin >> i;

	system("cls");



	return i;

}



class Galaxy {

private:

	int Counter;

	int Def;

	int Hp;

	int StarFlag = 1;

public:

	void Star_Flag(int a)

	{

		if (a == 1)StarFlag =1;

		else if (a == 0)StarFlag = 0;

	}

	int Get_StarFlag()

	{

		return StarFlag;

	}

	void Set_Star(int counter, int def, int hp)

	{

		Counter = counter;

		Def = def;

		Hp = hp;

	}

	void Destroyed(int a, int &Weapon_STR)

	{

		switch (a) {

		case 1:

			Hp -= Weapon_STR;

			break;

		case 2:

			Hp -= Weapon_STR;																 //은하도 추가 // 미사일그림 추가

			break;

		case 3:

			Hp -= Weapon_STR;

			break;

		case 4:

			Hp -= Weapon_STR;

			break;



		}

	}

	int Send_Hp()

	{

		return Hp;

	}



	int Send_Counter()

	{

		return Counter;

	}

};



class Arcade {

private:

	int Missile_Arcade;

	int Nuclear_Arcade;

	int Satellite_Arcade;

	int Stealth_Arcade;

	int Missile_Money = 50;

	int Nuclear_Money = 100;

	int Satellite_Money = 200;

	int Stealth_Money = 300;



public:

	void Set_Weapon(int missile, int nuclear, int satellite, int stealth)

	{

		Missile_Arcade = missile;

		Nuclear_Arcade = nuclear;

		Satellite_Arcade = satellite;

		Stealth_Arcade = stealth;



	}

	void Sell_Missile(int n)

	{

		int sell = Missile_Arcade - n;

		Missile_Arcade = sell;

	}

	void Sell_Nuclear(int n)

	{

		int sell = Nuclear_Arcade - n;

		Nuclear_Arcade = sell;

	}

	void Sell_Satellite(int n)

	{

		int sell = Satellite_Arcade - n;

		Satellite_Arcade = sell;

	}

	void Sell_Stealth(int n)

	{

		int sell = Stealth_Arcade - n;

		Stealth_Arcade = sell;

	}

	int Invoice_Missile(int a)

	{

		return Missile_Money*a;

	}

	int Invoice_Nuclear(int a)

	{

		return Nuclear_Money*a;

	}int Invoice_Satellite(int a)

	{

		return Satellite_Money*a;

	}int Invoice_Stealth(int a)

	{

		return Stealth_Money*a;

	}

	int Get_Missile()

	{

		return Missile_Arcade;

	}

	int Get_Nuclear()

	{

		return Nuclear_Arcade;

	}

	int Get_Satellite()

	{

		return Satellite_Arcade;

	}int Get_Stealth()

	{

		return Stealth_Arcade;

	}



};



class Black

{

private:

	int Tech;      //기술력

	int Missile;     //미사일

	int Missile_STR;    //미사일 위력

	int Nuclear;     //핵

	int Nuclear_STR;

	int Satellite;     //위성포

	int Satellite_STR;

	int Stealth;     //스텔스미사일

	int Stealth_STR;

	int Money;      //돈

	int Hp_black;			//체력





public:

	void Set_Data(int tech, int money, int hp)

	{

		Tech = tech;

		Money = money;

		Hp_black = hp;

	}

	void Buy_Weapon(Arcade &arcade1) //무기 구매 : 무기 상태에서 할수있는 선택지

	{

		int n;

		int i;

		gotoxy(43, 10);

		TextColor(3);

		cout << "무기구매                       " << endl;

		gotoxy(36, 12);

		TextColor(4);

		cout << "1. 미사일(기술력 : 100 필요)                       " << endl;

		gotoxy(36, 13);

		TextColor(5);

		cout << "2. 핵(기술력 : 200 필요)                      " << endl;

		gotoxy(36, 14);

		TextColor(6);

		cout << "3. 위성포(기술력 : 300 필요)                       " << endl;

		gotoxy(36, 15);

		TextColor(7);

		cout << "4. 스텔스 미사일(기술력 : 400 필요)                 " << endl << endl;

		gotoxy(38, 18);

		TextColor(4);

		cout << "상점 미사일 보유량" << arcade1.Get_Missile() << endl;

		gotoxy(38, 19);

		TextColor(5);

		cout << "상점 핵 보유량" << arcade1.Get_Nuclear() << endl;

		gotoxy(38, 20);

		TextColor(6);

		cout << "상점 위성포 보유량" << arcade1.Get_Satellite() << endl;

		gotoxy(38, 21);

		TextColor(7);

		cout << "상점 스텔스 미사일 보유량" << arcade1.Get_Stealth() << endl << endl << endl;

		gotoxy(38, 24);

		cout << "현재 보유한 돈 : " << Money << endl;





		cin >> n;



		system("cls");



		switch (n)

		{

		case 1:

			if (Tech < 100) {

				gotoxy(38, 5);

				TextColor(12);

				cout << "기술력이 100보다 작습니다" << endl;

			}

			else if (Tech > 100) {

				gotoxy(38, 10);

				TextColor(15);

				cout << n << "번을 선택하셧습니다." << endl;

				gotoxy(38, 12);

				cout << "수량을 선택해주세요" << endl;

				gotoxy(42, 13);

				cin >> i;



				arcade1.Sell_Missile(i);

				Missile += i;

				Money -= arcade1.Invoice_Missile(i);

				if (Missile >= 40)

				{

					Missile -= i;

					Money += arcade1.Invoice_Missile(i);

					gotoxy(38, 15);

					TextColor(12);

					cout << "40개이상 살 수 없습니다." << endl;

					gotoxy(38, 16);

					cout << "다시 적어주세요." << endl;

				}

				system("cls");

				break;

			}

		case 2:

			if (Tech < 200)

			{

				gotoxy(38, 5);

				TextColor(12);

				cout << "기술력이 200보다 작습니다" << endl;

			}

			else if (Tech > 200) {

				gotoxy(38, 10);

				TextColor(15);

				cout << n << "번을 선택하셧습니다." << endl;

				gotoxy(38, 12);

				cout << "수량을 선택해주세요" << endl;

				gotoxy(42, 13);

				cin >> i;



				arcade1.Sell_Nuclear(i);

				Nuclear += i;

				Money -= arcade1.Invoice_Nuclear(i);

				if (Nuclear >= 30)

				{

					Nuclear -= i;

					Money += arcade1.Invoice_Nuclear(i);

					gotoxy(38, 15);

					TextColor(12);

					cout << "30개이상 살 수 없습니다." << endl;

					gotoxy(38, 16);

					cout << "다시 고르세요." << endl;

				}

				system("cls");

				break;

			}

			break;

		case 3:if (Tech < 300) {

			gotoxy(38, 5);

			TextColor(12);

			cout << "기술력이 300보다 작습니다" << endl;

		}

			   else if (Tech > 300) {

				   gotoxy(38, 10);

				   TextColor(15);

				   cout << n << "번을 선택하셧습니다." << endl;

				   gotoxy(38, 12);

				   cout << "수량을 선택해주세요" << endl;

				   gotoxy(42, 13);

				   cin >> i;



				   arcade1.Sell_Satellite(i);

				   Satellite += i;

				   Money += arcade1.Invoice_Satellite(i);

				   if (Satellite >= 20)

				   {

					   Satellite -= i;

					   gotoxy(38, 15);

					   TextColor(12);

					   cout << "20개이상 살 수 없습니다." << endl;

					   gotoxy(38, 16);

					   cout << "다시 고르세요." << endl;

				   }

				   system("cls");

				   break;

			   }

			   break;

		case 4:if (Tech < 400) {

			gotoxy(38, 5);

			TextColor(12);

			cout << "기술력이 400보다 작습니다" << endl;

		}

			   else if (Tech > 400) {

				   gotoxy(38, 10);

				   TextColor(15);

				   cout << n << "번을 선택하셧습니다." << endl;

				   gotoxy(38, 12);

				   cout << "수량을 선택해주세요" << endl;

				   gotoxy(38, 13);

				   cin >> i;



				   arcade1.Sell_Stealth(i);

				   Stealth += i;

				   Money -= arcade1.Invoice_Stealth(i);

				   if (Stealth >= 10)

				   {

					   Stealth -= i;

					   Money += arcade1.Invoice_Stealth(i);

					   gotoxy(38, 15);

					   TextColor(12);

					   cout << "10개 이상 살 수 없습니다." << endl;

					   gotoxy(38, 16);

					   cout << "다시 고르세요." << endl;

				   }

				   system("cls");

				   break;

			   }

			   break;

		}





	}

	void Set_Weapon(int missile, int missile_str, int nuclear, int nuclear_str, int satellite, int satellite_str, int stealth, int stealth_str)

	{

		Missile = missile;

		Missile_STR = missile_str;

		Nuclear = nuclear;

		Nuclear_STR = nuclear_str;

		Satellite = satellite;

		Satellite_STR = satellite_str;

		Stealth = stealth;

		Stealth_STR = stealth_str;

	}

	void Status()    //엔지니어 현재상태

	{

		TextColor(14);

		cout << "현재 기술력은 : " << Tech << " 입니다." << endl;

		TextColor(15);

		cout << "현재 개발비는 : " << Money << " 가 있습니다. " << endl;

	}

	void Arsenal()      //무기 창고 : 현재 무기 수량과 스펙 수치.

	{

		TextColor(4);

		cout << "현재 미사일 개수 : " << Missile << endl;

		TextColor(5);

		cout << "현재 핵 개수 : " << Nuclear << endl;

		TextColor(6);

		cout << "현재 위성포 발사가능 횟수 : " << Satellite << endl;

		TextColor(7);

		cout << "현재 스텔스 미사일 발사가능 횟수 : " << Stealth << endl;

		system("pause");

		system("cls");

	}



	int Get_WeaponSTR(int i)

	{

		switch (i)

		{

		case 1: return Missile_STR;

		case 2: return Nuclear_STR;

		case 3: return Satellite_STR;

		case 4: return Stealth_STR;

		}

	}



	void Money_Making() {

		int Making_num;



		while (1) {

			gotoxy(38, 15);

			TextColor(14);

			cout << "1. 주사위 게임으로 돈벌기" << endl;

			gotoxy(38, 16);

			TextColor(12);

			cout << "2. 돌아가기" << endl;

			gotoxy(42, 17);

			cin >> Making_num;

			if (Making_num == 1) {

				Money++;

				srand((unsigned)time(NULL));

				int dice = (rand() % 6) + 1;

				Money += dice;

				gotoxy(38, 19);

				TextColor(10);

				cout << "주사위 값 : " << dice << endl;

				gotoxy(38, 20);

				TextColor(15);

				cout << "입금되었습니다. 현재 남은 개발비 : " << Money << endl;

				system("pause > null");

			}

			if (Making_num == 2) {

				system("cls");

				break;

			}

			system("cls");

		}       //돈벌기 : 1초에 10원씩, 주사위 함수 추가해서 주사위던지기로 돈벌기(5분제한)

	}

	void Drone();      //드론정찰 : 다른나라의 현재 기술력과 상태 보여주기

	void Research()

	{

		while (1) {

			int a;

			gotoxy(38, 20);

			TextColor(14);

			cout << "현재 기술력 : " << Tech;

			gotoxy(38, 21);

			TextColor(15);

			cout << "연구하시겠습니까?";

			gotoxy(38, 23);

			TextColor(5);

			cout << "1. 예" ;

			gotoxy(38, 24);

			TextColor(7);

			cout << "2. 아니요 ";

			gotoxy(44, 25);

			cin >> a;



			if (a == 1)

			{

				system("cls");

				gotoxy(44, 20);

				TextColor(6);

				cout << "연구중....연구중....." << endl;

				Sleep(100);

				system("cls");

				gotoxy(40, 17);

				TextColor(6);

				cout << "기술력이 증가하였습니다";

				gotoxy(42, 19);

				TextColor(15);

				cout <<"기술력 수치"<< Tech << " + 50" << endl;

				Tech += 50;

				gotoxy(44, 25);

				TextColor(6);

				cout << "현재 기술력 : " << Tech;

				system("pause>>null");

				system("pause");

				system("cls");

			}

			else if (a == 2)

			{

				system("cls");

				break;

			}

		}

	}

	void Attack(Galaxy &star, int a)     //공격하기 : 다른나라 폭격

	{

		int WeaponN;

		gotoxy(38, 10);

		TextColor(15);

		cout << "어느무기로 공격하시겠습니까?";

		gotoxy(44, 12);

		TextColor(4);

		cout << "1. 미사일";

		gotoxy(44, 13);

		TextColor(5);

		cout << "2. 핵";

		gotoxy(44, 14);

		TextColor(6);

		cout << "3. 위성포";

		gotoxy(44, 15);

		TextColor(7);

		cout << "4. 스텔스 미사일";

		switch (a) {

		case 1: gotoxy(44, 20); TextColor(8); cout << " 화성 HP : " << star.Send_Hp() << endl; break;

		case 2:	gotoxy(44, 21); TextColor(9); cout << " 수성 HP : " << star.Send_Hp() << endl; break;

		case 3:	gotoxy(44, 22); TextColor(10); cout << " 토성 HP : " << star.Send_Hp() << endl; break;

		case 4: gotoxy(44, 23); TextColor(11); cout << " LEIKSTERN HP : " << star.Send_Hp() << endl; break;

		}

		gotoxy(44, 26);

		TextColor(9);

		cout << "공학자 HP : " << Hp_black << endl;

		cin >> WeaponN;

		system("cls");



		gotoxy(33, 16);

		TextColor(12);

		cout << "★★★★★★★★★★★★★★★★★★";

		gotoxy(33, 17);

		cout << "★　　　　　　　　　　　　　　　　★";

		gotoxy(33, 18);

		cout << "★　　■■■　■　■■■　■■■　★";

		gotoxy(33, 19);

		cout << "★　　■　　　■　■　■　■　　　★";

		gotoxy(33, 20);

		cout << "★　　■■■　■　■■■　■■■　★";

		gotoxy(33, 21);

		cout << "★　　■　　　■　■　■　■　　　★";

		gotoxy(33, 22);

		cout << "★　　■　　　■　■　■　■■■　★";

		gotoxy(33, 23);

		cout << "★　　　　　　　　　　　　　　　　★";

		gotoxy(33, 24);

		cout << "★★★★★★★★★★★★★★★★★★";

		system("pause");

		system("cls");



		switch (WeaponN) {

		case 1:

			if (Missile <= 0)

			{



				gotoxy(44, 19);

				TextColor(12);

				cout << "미사일이 없습니다" << endl;

				gotoxy(44, 21);

				TextColor(15);

				cout << "돈을 벌어서 사주세요" << endl;

				system("pause");

				system("cls");

			}

			else

			{

					star.Destroyed(WeaponN, Missile_STR);

					gotoxy(44, 19);

					TextColor(11);

					cout << "폭격 완료" << endl;

					if (star.Send_Hp() <= 0)

					{

						gotoxy(42, 21);

						TextColor(12);

						cout << "별이 폭발하였습니다.";

						system("pause");

						system("cls");

						star.Star_Flag(0);

						break;

					}

					gotoxy(44, 21);

					TextColor(14);

					cout << "이 별의 현재 체력 : " << star.Send_Hp() << endl << endl;

					Counter_Attack(star);

					Missile--;

				}

				break;



		case 2:

			if (Nuclear <= 0)

			{

				gotoxy(44, 19);

				TextColor(12);

				cout << "핵미사일이 없습니다" << endl;

				gotoxy(44, 21);

				TextColor(15);

				cout << "돈을 벌어서 사주세요" << endl;

				system("pause");

				system("cls");

			}

			else

			{

				star.Destroyed(WeaponN, Nuclear_STR);

				gotoxy(44, 19);

				TextColor(11);

				cout << "폭격 완료" << endl;

				if (star.Send_Hp() <= 0)

				{

					gotoxy(42, 21);

					TextColor(12);

					cout << "별이 폭발하였습니다.";

					system("pause");

					system("cls");

					star.Star_Flag(0);

					break;

				}

				gotoxy(44, 21);

				TextColor(14);

				cout << "이 별의 현재 체력 : " << star.Send_Hp() << endl << endl;

				Counter_Attack(star);

				Nuclear--;



			}

			break;

		case 3:

			if (Satellite <= 0)

			{

				gotoxy(44, 19);

				TextColor(12);

				cout << "위성포가 없습니다" << endl;

				gotoxy(44, 21);

				TextColor(15);

				cout << "돈을 벌어서 사주세요" << endl;

				system("pause");

				system("cls");

			}

			else

			{

				star.Destroyed(WeaponN, Satellite_STR);

				gotoxy(44, 19);

				TextColor(11);

				cout << "폭격완료" << endl;

				if (star.Send_Hp() <= 0)

				{

					gotoxy(42, 21);

					TextColor(12);

					cout << "별이 폭발하였습니다.";

					system("pause");

					system("cls");

					star.Star_Flag(0);

					break;

				}

				gotoxy(44, 21);

				TextColor(14);

				cout << "이 별의 현재 체력 : " << star.Send_Hp() << endl << endl;

				Counter_Attack(star);

				Satellite--;

			}

			break;

		case 4:

			if (Stealth <= 0)

			{

				gotoxy(44, 19);

				TextColor(12);

				cout << "스텔스 미사일이 없습니다" << endl;

				gotoxy(44, 21);

				TextColor(15);

				cout << "돈을 벌어서 사주세요" << endl;

				system("pause");

				system("cls");

			}

			else

			{

				int a = Get_WeaponSTR(WeaponN);

				star.Destroyed(WeaponN, a);

				gotoxy(44, 19);

				TextColor(11);

				cout << "폭격 완료" << endl;

				if (star.Send_Hp() <= 0)

				{

					gotoxy(42, 21);

					TextColor(12);

					cout << "별이 폭발하였습니다.";

					system("pause");

					system("cls");

					star.Star_Flag(0);

					break;

				}

				gotoxy(44, 21);

				TextColor(14);

				cout << "이 별의 현재 체력 : " << star.Send_Hp() << endl << endl;

				Stealth--;

				system("pause");

				system("cls");

			}



			system("pause");

			system("cls");

			break;

		}

	}

	void Counter_Attack(Galaxy &star)

	{

		Hp_black -= star.Send_Counter();

		TextColor(3);

		gotoxy(40, 25);

		TextColor(12);

		cout << "*************EMERGENCY****************" << endl;

		gotoxy(40, 27);

		TextColor(15);

		cout << "***********별에서 카운터어택*********** " << endl;

		gotoxy(40, 29);

		TextColor(12);

		cout << "*************EMERGENCY****************" << endl;

		gotoxy(44, 31);

		TextColor(12);

		cout << " 검은 공학자  HP : " << Hp_black << endl;

		if (Hp_black <= 0) {

			gotoxy(44, 33);

			TextColor(12);

			cout << "공학자가 사망하였습니다.";

			cout << "게임을 종료합니다. ";

			exit(0);

		}

		system("pause");

		system("cls");

	}

};







void main()

{

	system("title LeikStern-972");

	ConsoleSize();

	Black Engineer;

	Engineer.Set_Data(1000, 10000, 300);

	Engineer.Set_Weapon(0, 50, 0, 100, 0, 200, 0, 100);



	Arcade arcade1;

	arcade1.Set_Weapon(100, 100, 100, 100);



	Galaxy mars;

	mars.Set_Star(10, 30, 100);



	Galaxy mercury;

	mercury.Set_Star(50, 100, 100);



	Galaxy saturn;

	saturn.Set_Star(100, 200, 100);



	Galaxy sun;

	sun.Set_Star(1000, 500, 100);





	gotoxy(50, 25);



	cout << "LEIKSTERN-972  :  Universe Distruction" << endl;

	system("pause>>null");

	system("pause");



	gotoxy(57, 27);



	cout << "개발자  :  Team.Black Engineer" << endl;

	system("pause>>null");

	system("pause");

	system("cls");









	gotoxy(38, 27);

	cout << "이것은 한 검은 공학자의 이야기....." << endl;

	system("pause>>null");

	system("pause");

	system("cls");

	gotoxy(38, 27);

	cout << "그는 세상을 멸망시키려고 하는데..." << endl;

	system("pause>>null");

	system("pause");

	system("cls");

	gotoxy(38, 27);

	cout << "용사여! 그가 되어 세상을 멸망시켜주세요!" << endl;

	system("pause>>null");

	system("pause");

	system("cls");

	gotoxy(38, 27);

	cout << "돈을 벌고 기술력을 연마하여 무기를 사고 쏘세요! 쉽죠?" << endl;

	system("pause>>null");

	system("pause");

	system("cls");

	gotoxy(38, 27);

	cout << "게임을 시작합니다" << endl;

	system("pause>>null");

	system("pause");

	system("cls");









	while (true) {

		int StarN = 0;

		int newgame = Game_menu();

		switch (newgame)

		{

		case 1:gotoxy(38, 9);

			TextColor(15);

			cout << "폭격할 별을 선택해주세요!" << endl;



			gotoxy(18, 32);

			TextColor(8);

			if (mars.Get_StarFlag() == 1)

			{

				cout << "1. 화성  " << endl;

			}

			else

			{

				TextColor(0); cout << "  죽은별   " << endl;

			}



			gotoxy(20, 30);

			TextColor(12);

			if (mars.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else

			{

				TextColor(0); cout << "*" << endl;

			}





			gotoxy(28, 30);

			TextColor(9);

			if (mercury.Get_StarFlag() == 1)

			{

				cout << "2. 수성  " << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(30, 28);

			TextColor(9);

			if (mercury.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << "*" << endl; }





			gotoxy(38, 29);

			TextColor(10);

			if (saturn.Get_StarFlag() == 1)

			{

			cout << "3. 토성" << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(40, 27);

			TextColor(10);

			if (saturn.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << " * " << endl; }



			/////////////////////////////////////////////////////////



			gotoxy(48, 31);

			TextColor(11);

			if (sun.Get_StarFlag() == 1)

			{

			cout << "4. LEIKSTERN-972" << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(54, 29);

			TextColor(11);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << "*" << endl; }

			/////////////////////////////////////////////////////////



			gotoxy(46, 36);

			TextColor(6);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "(북두칠성 완성용 별)" << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(65, 34);

			TextColor(6);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << "*" << endl; }

			/////////////////////////////////////////////////////////



			gotoxy(68, 36);

			TextColor(13);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "(북두칠성 완성용 별)" << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(76, 34);

			TextColor(13);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << "*" << endl; }



			/////////////////////////////////////////////////////////



			gotoxy(78, 31);

			TextColor(3);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "(북두칠성 완성용 별)" << endl;

			}

			else { TextColor(0); cout << "  죽은별   " << endl; }



			gotoxy(86, 29);

			TextColor(3);

			if (sun.Get_StarFlag() == 1)

			{

				cout << "★" << endl;

			}

			else { TextColor(0); cout << "*" << endl; }















			gotoxy(50, 21);

			TextColor(15);

			cin >> StarN;

			system("cls");

			switch (StarN)

			{

			case 1:Engineer.Attack(mars, StarN);

				break;

			case 2:Engineer.Attack(mercury, StarN);

				break;

			case 3:Engineer.Attack(saturn, StarN);

				break;

			case 4:Engineer.Attack(sun, StarN);

				break;

			}

			if (mars.Get_StarFlag() == 0 && mercury.Get_StarFlag() == 0 && saturn.Get_StarFlag() == 0 && sun.Get_StarFlag() == 0)

			{

				gotoxy(38, 20);

				TextColor(9);

				cout << "GAME COMPLETE";

				system("pause");

				system("cls");



				gotoxy(38, 20);

				TextColor(12);

				cout << "우주멸망 ㅅㄱ";

				system("pause");

				system("cls");

				gotoxy(38, 20);

				TextColor(12);

				cout << "The end....";

				exit(0);

			}

			break;

			system("cls");

			//break;

		case 2: Engineer.Status();

			break;

			system("cls");

		case 3: Engineer.Arsenal();

			break;

			system("pause");

			system("cls");

		case 4: Engineer.Buy_Weapon(arcade1);

			break;

			system("cls");

		case 5: Engineer.Money_Making();

			break;

			system("cls");

		case 6: Engineer.Research();

			break;

			system("cls");

		}

	}

}
