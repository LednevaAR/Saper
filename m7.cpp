#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <time.h>
#include <SFML/Network.hpp>
#include <unistd.h>
#include <sstream>
#include <math.h>
#include <sys/times.h>
#include <fstream>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#define N 9
#define n 9
#define rand1() (fabs(sin(rand())))

using namespace std;

class Button
{
	private:
		int x;
		int y;
		int num;		//button press counter
		int bn;			//amount of bomb near
		int par;
		int what;
		int check;
	public:
		//Button();
		
		sf::Sprite sprite;
		sf::Image image1;
		sf::Texture texture1;

		void set_x(int);
		int  get_x();
		void set_y(int);
		int  get_y();

		void set_num(int);
		int  get_num();

		void set_bn(int);
		int  get_bn();

		void set_par(int);
		int  get_par();
		
		void set_check(int);
                int  get_check();
		
		void set_what(int);
		int  get_what();

		void butput();
		void butput1();
};

void Button::set_x(int X)
{
	x = X;
}

int Button::get_x()
{
	return x;
}

void Button::set_y(int Y)
{
	y = Y;
}

int Button::get_y()
{
	return y;
}

void Button::set_num(int Num)
{
	num = Num;
}

int  Button::get_num()
{
	return num;
}

void Button::set_what(int What)
{
	what = What;
}

int  Button::get_what()
{
	return what;
}

void Button::set_bn(int abn)
{
	bn = abn;
}

int Button::get_bn()
{
	return bn;
}

void Button::set_check(int Check)
{
        check = Check;
}

int  Button::get_check()
{
        return check;
}

void Button::set_par(int Par)
{
	par = Par;
}

int  Button::get_par()
{
	return par;
}

void Button::butput()
{
        num++;
}
void Button::butput1()
{         
        par = 17;
}

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp) 
{
        if (sprite.contains(mp)){
                return true;
        }
        return false;
}
sf::String Ach[20][2];
std::ofstream fout("1.txt", std::ios::app);
std::ofstream fort("2.txt", std::ios::app);
void func();

char * settime(struct tm *u)
{
	char s[40];
	char *tmp;
	for (int i = 0; i<40; i++) s[i] = 0;
	int length = strftime(s, 40, "%d.%m.%Y %H:%M:%S, %A", u);
	tmp = (char*)malloc(sizeof(s));
	strcpy(tmp, s);
	return(tmp);
}

int CountLinesInFile(string filename)
{
  ifstream F(filename, ios::in);
  if (!F)
  {
    return -1;
  }
  int count = 0;
  char buffer[1000]; // буфер для сохранения одной строки
  while (!F.eof())
  {
    count++;
    F.getline(buffer, 1000);
  }
  F.close();
  return count;
}

int GetStringsFromFileS(string filename, string** _lines)
{
  string* lines; // временный список строк
  int n1 = CountLinesInFile(filename); // Получить количество строк в файле
  if (n1 == -1) return -1;
  ifstream F(filename);
  if (!F) return -1;
  try
  {
    lines = new string[n1];
  }
  catch (bad_alloc e)
  {
    cout << e.what() << endl; // вывести сообщение об ошибке
    F.close();
    return -2; // возврат с кодом -2
  }
  char buffer[1000]; // буфер для чтения строки

  for (int i = 0; i < n1; i++)
  {
    F.getline(buffer, 1000);
    int len;
    for (len = 0; buffer[len] != '\0'; len++);
    lines[i].assign(buffer, len);
  }
  F.close();
  *_lines = lines;
  return n1;
}

void menu() {
	sf::RenderWindow window2(sf::VideoMode(300, 170), "Menu");
	sf::Image imagep, imagea;
	sf::Texture texturep, texturea;
	sf::Sprite spritep, spritea;
	imagep.loadFromFile("play.png");
	texturep.loadFromImage(imagep);
	spritep.setTexture(texturep);
	spritep.setPosition(19, 30);
	imagea.loadFromFile("ach.png");
	texturea.loadFromImage(imagea);
	spritea.setTexture(texturea);
	spritea.setPosition(19, 100);
	window2.setPosition(sf::Vector2i(500, 300));
	while (window2.isOpen())
	{
		sf::Event event2;
		while (window2.pollEvent(event2))
		{
			if (event2.type == sf::Event::Closed)
				window2.close();
		}
		if(isSpriteHover(spritep.getGlobalBounds(), sf::Vector2f(event2.mouseButton.x, event2.mouseButton.y)) == true)
		{
			if(event2.type == sf::Event::MouseButtonReleased && event2.mouseButton.button == sf::Mouse::Left) {
				window2.close();
				func();
				return;
			}
		}
		if(isSpriteHover(spritea.getGlobalBounds(), sf::Vector2f(event2.mouseButton.x, event2.mouseButton.y)) == true)
		{
			if(event2.type == sf::Event::MouseButtonReleased && event2.mouseButton.button == sf::Mouse::Left) {
				sf::RenderWindow window3(sf::VideoMode(800, 1000), "Acievement table");
				while (window3.isOpen())
				{
					sf::Event event3;
					while (window3.pollEvent(event3))
					{
						if (event3.type == sf::Event::Closed)
							window3.close();
					}
					window3.clear(sf::Color::White);
					std::stringstream ss0;
					for (int k1 = 0; k1 < 20; k1++) {
						ifstream input("1.txt");
					    	int ch;
					    	int t = 0;
						int count = 0;
						while (input >> ch)
							count++;
					    	input.close();  
						int *mass = new int[count];
						int *mass1 = new int[count];
						ifstream file("1.txt");
						for (int i = 0; i < count; i++) {
							file >> mass[i];
							//cout << mass1[i] << " ";
						}
						file.close();
						ifstream file1("1.txt");
						for (int i = 0; i < count; i++) {
							file1 >> mass1[i];
							//cout << mass1[i] << " ";
						}
						file1.close();
						string* lines = nullptr;
						int count1 = GetStringsFromFileS("2.txt", &lines);
						sort(mass1, mass1 + count);
						int k = 0;
						for (int i = count - 1; i >= 0; i--) {
							std::stringstream ss;
							ss << mass1[i];
							for (int j = 0; j < count; j++) {
								if (mass1[i] == mass[j]) {
									mass[j] = -1;
									t = j;
									break;
								}
							}
							if (k < 20) {
								Ach[k][0] = ss.str();
								Ach[k][1] = lines[t];
								k += 1;
							}
						}
						file.close();
						std::stringstream ss0;
						ss0 << k1 + 1;
						sf::Font font;
						font.loadFromFile("CyrilicOld.TTF");
						sf::Text text1("", font, 30), text2("", font, 30), text3("", font, 30);
						text1.setString(Ach[k1][0]);
						text2.setString(Ach[k1][1]);
						text3.setString(ss0.str());
						text1.setFillColor(sf::Color::Black);
						text2.setFillColor(sf::Color::Black);
						text3.setFillColor(sf::Color::Black);
						text1.setStyle(sf::Text::Bold);
						text2.setStyle(sf::Text::Bold);
						text3.setStyle(sf::Text::Bold);
						text3.setPosition(50, 10 + k1*50);
						text1.setPosition(200, 10 + k1*50);
						text2.setPosition(350, 10 + k1*50);
						window3.draw(text1);
						window3.draw(text2);
						window3.draw(text3);
					}
					window3.display();
				}
			}
		}
		window2.clear(sf::Color::White);
		window2.draw(spritep);
		window2.draw(spritea);
		window2.display();
    	}
    	return;
}

int OpenAll(int i, int j, Button (*button)[N], int points)
{
        button[i][j].image1.loadFromFile("0.png");
        button[i][j].texture1.loadFromImage(button[i][j].image1);
	button[i][j].sprite.setTexture(button[i][j].texture1);
	button[i][j].set_what(1);
	button[i][j].set_par(17);
//	points++;
	if (i!=0)
	       if (button[i-1][j].get_what() == 0 && button[i-1][j].get_par() != 17)
	       {
			switch (button[i-1][j].get_bn()) {
                        	case 1:
                                	button[i-1][j].image1.loadFromFile("1.png");
                                        break;
                                case 2:
                                        button[i-1][j].image1.loadFromFile("2.png");
                                        break;
                                case 3:
                                        button[i-1][j].image1.loadFromFile("3.png");
                                        break;
                                case 4:
                                        button[i-1][j].image1.loadFromFile("4.png");
                                        break;
                                case 5:
                                        button[i-1][j].image1.loadFromFile("5.png");
                                        break;
                                case 6:
                                        button[i-1][j].image1.loadFromFile("6.png");
                                        break;
                                case 7:
                                        button[i-1][j].image1.loadFromFile("7.png");
                                        break;
                                case 8:
                                        button[i-1][j].image1.loadFromFile("8.png");
                                        break;
                                case 0:
                                        points = OpenAll(i-1, j, button, points);
                                        break;
			}               
	      		
	      		button[i-1][j].texture1.loadFromImage(button[i-1][j].image1);
        		button[i-1][j].sprite.setTexture(button[i-1][j].texture1);
        		button[i-1][j].set_what(1);
			button[i-1][j].set_par(17);
			points++;
	       }
	       
        if (i!=N-1) 
		if (button[i+1][j].get_what() == 0 && button[i+1][j].get_par() != 17)
               {
                        switch (button[i+1][j].get_bn()) {
                                case 1:
                                        button[i+1][j].image1.loadFromFile("1.png");
                                        break;
                                case 2:
                                        button[i+1][j].image1.loadFromFile("2.png");
                                        break;
                                case 3:
                                        button[i+1][j].image1.loadFromFile("3.png");
                                        break;
                                case 4:
                                        button[i+1][j].image1.loadFromFile("4.png");
                                        break;
                                case 5:
                                        button[i+1][j].image1.loadFromFile("5.png");
                                        break;
                                case 6:
                                        button[i+1][j].image1.loadFromFile("6.png");
                                        break;
                                case 7:
                                        button[i+1][j].image1.loadFromFile("7.png");
                                        break;
                                case 8:
                                        button[i+1][j].image1.loadFromFile("8.png");
                                        break;
                                case 0:
                                        points = OpenAll(i+1, j, button, points);
                                        break;
                        }
			button[i+1][j].texture1.loadFromImage(button[i+1][j].image1);
                        button[i+1][j].sprite.setTexture(button[i+1][j].texture1);
                        button[i+1][j].set_what(1);
                        button[i+1][j].set_par(17);
			points++;
               }

	if (j!=0) 
		if (button[i][j-1].get_what() == 0 && button[i][j-1].get_par() != 17)
               {
                        switch (button[i][j-1].get_bn()) {
                                case 1:
                                        button[i][j-1].image1.loadFromFile("1.png");
                                        break;
                                case 2:
                                        button[i][j-1].image1.loadFromFile("2.png");
                                        break;
                                case 3:
                                        button[i][j-1].image1.loadFromFile("3.png");
                                        break;
                                case 4:
                                        button[i][j-1].image1.loadFromFile("4.png");
                                        break;
                                case 5:
                                        button[i][j-1].image1.loadFromFile("5.png");
                                        break;
                                case 6:
                                        button[i][j-1].image1.loadFromFile("6.png");
                                        break;
                                case 7:
                                        button[i][j-1].image1.loadFromFile("7.png");
                                        break;
                                case 8:
                                        button[i][j-1].image1.loadFromFile("8.png");
                                        break;
                                case 0:
                                        points = OpenAll(i, j-1, button, points);
                                        break;
                        }
                        button[i][j-1].texture1.loadFromImage(button[i][j-1].image1);
                        button[i][j-1].sprite.setTexture(button[i][j-1].texture1);
                        button[i][j-1].set_what(1);
                        button[i][j-1].set_par(17);
			points++;
               }

	if (j!=N-1) 
		if (button[i][j+1].get_what() == 0 && button[i][j+1].get_par() != 17)
               {
                        switch (button[i][j+1].get_bn()) {
                                case 1:
                                        button[i][j+1].image1.loadFromFile("1.png");
                                        break;
                                case 2:
                                        button[i][j+1].image1.loadFromFile("2.png");
                                        break;
                                case 3:
                                        button[i][j+1].image1.loadFromFile("3.png");
                                        break;
                                case 4:
                                        button[i][j+1].image1.loadFromFile("4.png");
                                        break;
                                case 5:
                                        button[i][j+1].image1.loadFromFile("5.png");
                                        break;
                                case 6:
                                        button[i][j+1].image1.loadFromFile("6.png");
                                        break;
                                case 7:
                                        button[i][j+1].image1.loadFromFile("7.png");
                                        break;
                                case 8:
                                        button[i][j+1].image1.loadFromFile("8.png");
                                        break;
                                case 0:
                                        points = OpenAll(i, j+1, button, points);
                                        break;
                        }
                        button[i][j+1].texture1.loadFromImage(button[i][j+1].image1);
                        button[i][j+1].sprite.setTexture(button[i][j+1].texture1);
                        button[i][j+1].set_what(1);
                        button[i][j+1].set_par(17);
			points++;
               }
        return points;
}

void func() {
	//int n = 9;
	int sum = 0;
	int gen = 2;
	int points = 0;
	const int x1 = 1000, y1 = 1000;
	int x0 = 500, y0 = 500;
        sf::RenderWindow window/*, window2, window3*/;
        window.create(sf::VideoMode(1000, 1000),"Sapper");
        
        sf::Image image, image0, image11, image2, image3, image4;
        Button button[n][n];
        int k1;
        Button ** A = (Button**) malloc (sizeof (Button*) * x1);
	for (int i = 0; i < x1; i++) {  A [i] = (Button*) malloc (sizeof (Button)*y1);}
	srand(time(NULL));
	/*for (int i1 = 0; i1 < n + 1; i1++)
   	{                
      		k1 = abs(k1 + rand()) % (n * n);
      		button[k1 / n][k1 % n].set_bn(-1);
   	}*/
   	while (sum != 10)
   	{                
      		k1 = (int) ((n * n) * rand1());
      		if (button[k1 / n][k1 % n].get_bn() != -1) {
      			printf("%d\n", k1);
      			sum += 1;
      			button[k1 / n][k1 % n].set_bn(-1);
      		}
   	}
	//sf::Image image1[n][n];
        image.loadFromFile("but.png");
        image11.loadFromFile("kn.png");
        image2.loadFromFile("kn1.png");
        image3.loadFromFile("knu.png");
        image4.loadFromFile("knd.png");
	sf::Texture texture, texture0, texture11, texture2, texture3, texture4;
	//sf::Texture texture1[n][n];
    	texture.loadFromImage(image);
    	texture11.loadFromImage(image11);
    	texture2.loadFromImage(image2);
    	texture3.loadFromImage(image3);
    	texture4.loadFromImage(image4);
        sf::Sprite /*sprite[n][n],*/ sprite0, sprite11, sprite2, sprite3, sprite4;
	sf::Font font;
	font.loadFromFile("CyrilicOld.TTF");
	sf::Text text("", font, 30);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setString("0");
	text.setPosition(10, 0);
	int a = 0, b = 0, abn;
	sprite11.setTexture(texture11);
	sprite11.setPosition(0, 80);
	sprite2.setTexture(texture2);
	sprite2.setPosition(537, 80);
	sprite3.setTexture(texture3);
	sprite3.setPosition(60, 20);
	sprite4.setTexture(texture4);
	sprite4.setPosition(60, 575);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
        		a = 53*j + 60;
                       b = 55*i + 80;
			button[i][j].set_num(0);
			button[i][j].sprite.setTexture(texture);
			button[i][j].set_what(0);
			button[i][j].sprite.setPosition(a, b);
			window.draw(button[i][j].sprite);
			if (button[i][j].get_bn() != -1) {
				abn = 0;

				if (i == 0)
				{
					if (j == 0)
						abn = (button[i][j+1].get_bn() == -1) + (button[i+1][j].get_bn() == -1) + (button[i+1][j+1].get_bn() == -1);	
					else if (j == N-1)
						abn = (button[i][j-1].get_bn() == -1) + (button[i+1][j-1].get_bn() == -1) + (button[i+1][j].get_bn() == -1);
					else
						abn = (button[i][j-1].get_bn() == -1) + (button[i+1][j-1].get_bn() == -1) + (button[i+1][j].get_bn() == -1) + (button[i+1][j+1].get_bn() == -1) + (button[i][j+1].get_bn() == -1);
				}

				if (i == N-1)
        			{
                			if (j == 0)
                        			abn = (button[i][j+1].get_bn() == -1) + (button[i-1][j].get_bn() == -1) + (button[i-1][j+1].get_bn() == -1);
                			else if (j == N-1)
                        			abn = (button[i][j-1].get_bn() == -1) + (button[i-1][j-1].get_bn() == -1) + (button[i-1][j].get_bn() == -1);
                			else
                        			abn = (button[i][j-1].get_bn() == -1) + (button[i-1][j-1].get_bn() == -1) + (button[i-1][j].get_bn() == -1) + (button[i-1][j+1].get_bn() == -1) + (button[i][j+1].get_bn() == -1);
        			}

				if (j == 0 && i != 0 && i != (N-1))
					abn = (button[i-1][j].get_bn() == -1) + (button[i-1][j+1].get_bn() == -1) + (button[i][j+1].get_bn() == -1) + (button[i+1][j+1].get_bn() == -1) + (button[i+1][j].get_bn() == -1);
	
				if (j == (N-1) && i != 0 && i != (N-1))
                			abn = (button[i-1][j].get_bn() == -1) + (button[i-1][j-1].get_bn() == -1) + (button[i][j-1].get_bn() == -1) + (button[i+1][j-1].get_bn() == -1) + (button[i+1][j].get_bn() == -1);

				if (i != 0 && i != (N-1) && j != 0 && j != (N-1))
					abn = (button[i-1][j-1].get_bn() == -1) + (button[i-1][j].get_bn() == -1) + (button[i-1][j+1].get_bn() == -1) + (button[i][j+1].get_bn() == -1) + (button[i+1][j+1].get_bn() == -1) + (button[i+1][j].get_bn() == -1) + (button[i+1][j-1].get_bn() == -1) + (button[i][j-1].get_bn() == -1);
			button[i][j].set_bn(abn);
			}
		}
	}
	sf::Vector2f mp;
        mp.x = sf::Mouse::getPosition(window).x;
        mp.y = sf::Mouse::getPosition(window).y;
	while (window.isOpen())
    	{
		sf::Event event;
        	while (window.pollEvent(event))
        	{
            		if(event.type == sf::Event::Closed) {
		              	std::ofstream fout("1.txt", std::ios::app);
		              	std::ofstream fort("2.txt", std::ios::app);
				fout << points << std::endl;
				fout.close();
				struct tm *u;
				char *f;
				const time_t timer = time(NULL);
				u = localtime(&timer);
				f = settime(u);
				fort << f << std::endl;
				fort.close();
            			window.close();
            		}
        	}
		for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
				if(isSpriteHover(button[i][j].sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
 	        		{
 	        			if(event.type == sf::Event::MouseButtonReleased /*&& event.mouseButton.button == sf::Mouse::Right*/ && (sf::Mouse::isButtonPressed(sf::Mouse::Right)) && (button[i][j].get_par() != 17)) {
						button[i][j].butput();
						//printf("%d", num[i][j]);
						if (button[i][j].get_num() % 2 == 1) { 
							button[i][j].image1.loadFromFile("flag.png");
							button[i][j].set_what(2);
						}
						else if (button[i][j].get_num() % 2 == 0) { 
							button[i][j].image1.loadFromFile("but.png");
							button[i][j].set_what(0);
						}
                                              button[i][j].texture1.loadFromImage(button[i][j].image1);
                                              button[i][j].sprite.setTexture(button[i][j].texture1);
                                              A[y0 + i][x0 + j].set_num(button[i][j].get_num());
						A[y0 + i][x0 + j].set_bn(button[i][j].get_bn());
						A[y0 + i][x0 + j].set_par(button[i][j].get_par());
						A[y0 + i][x0 + j].set_what(button[i][j].get_what());
						A[y0 + i][x0 + j].set_check(button[i][j].get_check());
					}
 	        			if(event.type == sf::Event::MouseButtonReleased && /*event.mouseButton.button == sf::Mouse::Left &&*/ (sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
						//button[i][j].image1.loadFromFile("1.png");
						button[i][j].set_what(1);
						if(button[i][j].get_par()!=17) {
							switch (button[i][j].get_bn()) {
								case 1:
									  button[i][j].image1.loadFromFile("1.png");
									  break;
								case 2:
		                                                        button[i][j].image1.loadFromFile("2.png");
		                                                        break;
								case 3:
		                                                        button[i][j].image1.loadFromFile("3.png");
		                                                        break;
								case 4:
		                                                        button[i][j].image1.loadFromFile("4.png");
		                                                        break;
								case 5:
		                                                        button[i][j].image1.loadFromFile("5.png");
		                                                        break;
								case 6:
		                                                        button[i][j].image1.loadFromFile("6.png");
		                                                        break;
								case 7:
		                                                        button[i][j].image1.loadFromFile("7.png");
		                                                        break;
								case 8:
		                                                        button[i][j].image1.loadFromFile("8.png");
		                                                        break;
								case 0:
									  //button[i][j].image1.loadFromFile("0.png");
									  points = OpenAll(i, j, button, points) + 1;
		                                                        break;
								case -1:
									  button[i][j].image1.loadFromFile("bomb.png");
		                                                        break;
							}	
						}	
						button[i][j].texture1.loadFromImage(button[i][j].image1);
						button[i][j].sprite.setTexture(button[i][j].texture1);
						button[i][j].set_check(1);
						A[y0 + i][x0 + j].set_num(button[i][j].get_num());
						A[y0 + i][x0 + j].set_bn(button[i][j].get_bn());
						A[y0 + i][x0 + j].set_par(button[i][j].get_par());
						A[y0 + i][x0 + j].set_what(button[i][j].get_what());
						A[y0 + i][x0 + j].set_check(button[i][j].get_check());
						std::stringstream ss;
                                              ss << points;
                                              text.setString(ss.str());
						window.draw(button[i][j].sprite);
						window.display();
						//для бомбы
						if (button[i][j].get_bn() == -1) {
							//sleep(1);
							sf::RenderWindow window1(sf::VideoMode(300, 100), "Defeat");
							image0.loadFromFile("butt.png");
                                                	texture0.loadFromImage(image0);
                                                	sprite0.setTexture(texture0);
							sprite0.setPosition(19, 30);
							window1.setPosition(sf::Vector2i(500, 300));
							//std::stringstream ss;
                                              	//ss << points;
                                              	//text.setString(ss.str());
                                              	std::ofstream fout("1.txt", std::ios::app);
                                              	std::ofstream fort("2.txt", std::ios::app);
    							fout << points << std::endl;
    							fout.close();
    							struct tm *u;
							char *f;
							const time_t timer = time(NULL);
							u = localtime(&timer);
							f = settime(u);
							fort << f << std::endl;
							fort.close();
							window.close();
							while (window1.isOpen())
    							{
        							sf::Event event1;
        							while (window1.pollEvent(event1))
        							{
            								if (event1.type == sf::Event::Closed)
                								window1.close();
        							}
								if(isSpriteHover(sprite0.getGlobalBounds(), sf::Vector2f(event1.mouseButton.x, event1.mouseButton.y)) == true)
                                				{
                                        				if(event1.type == sf::Event::MouseButtonReleased && event1.mouseButton.button == sf::Mouse::Left) {
										window1.close();
										menu();
										return;
									}
								}
        							window1.clear(sf::Color::White);
								window1.draw(sprite0);
        							window1.display();
    							}
    						}
						//конец
						else {
							if (button[i][j].get_par() != 17) {
								points += 1;
								std::stringstream ss;
								ss << points;
								text.setString(ss.str());
								button[i][j].butput1();
							}
							A[y0 + i][x0 + j].set_num(button[i][j].get_num());
							A[y0 + i][x0 + j].set_bn(button[i][j].get_bn());
							A[y0 + i][x0 + j].set_par(button[i][j].get_par());
							A[y0 + i][x0 + j].set_what(button[i][j].get_what());
							A[y0 + i][x0 + j].set_check(button[i][j].get_check());
						}
						if (i == 0) {
							y0 += 1;
							gen = 2;
							for (int j1 = 0; j1 < n; j1++) {
								for (int i1 = n - 1; i1 >= 1; i1--) {
									button[i1][j1].set_bn(button[i1 - 1][j1].get_bn());
									button[i1][j1].set_num(button[i1 - 1][j1].get_num());
									button[i1][j1].set_par(button[i1 - 1][j1].get_par());
									button[i1][j1].set_what(button[i1 - 1][j1].get_what());
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									A[y0 + i1][x0 + j1].set_num(button[i1][j1].get_num());
									A[y0 + i1][x0 + j1].set_bn(button[i1][j1].get_bn());
									A[y0 + i1][x0 + j1].set_par(button[i1][j1].get_par());
									A[y0 + i1][x0 + j1].set_what(button[i1][j1].get_what());
									A[y0 + i1][x0 + j1].set_check(button[i1][j1].get_check());
									button[i1][j1].texture1.loadFromImage(button[i1][j1].image1);
									button[i1][j1].sprite.setTexture(button[i1][j1].texture1);
									//window.draw(button[i][j].sprite);
									//window.display();
								}
								if (A[y0][x0 + j1].get_check() == 0) {
									gen = 0;
								}
							}
							if (gen == 0) {
								srand(time(NULL));
								sum = 0;
								int k2 = (int) ((3) * rand1());
								cout << "*";
								while (sum != 2)
								{
									k1 = (int) ((9) * rand1());
									if (button[0][k1].get_bn() != -1) {
										printf("%d\n", k1);
										sum += 1;
										button[0][k1].set_bn(-1);
										button[0][k1].set_check(1);
									}
								}
								for (int j1 = 0; j1 < n; j1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
									button[0][j1].set_what(0);
									A[y0][x0 + j1].set_num(button[0][j1].get_num());
									A[y0][x0 + j1].set_bn(button[0][j1].get_bn());
									A[y0][x0 + j1].set_par(button[0][j1].get_par());
									A[y0][x0 + j1].set_what(button[0][j1].get_what());
									A[y0][x0 + j1].set_check(button[0][j1].get_check());
									button[0][j1].image1.loadFromFile("but.png");
									button[0][j1].texture1.loadFromImage(button[0][j1].image1);
									button[0][j1].sprite.setTexture(button[0][j1].texture1);
								}
							} if (gen != 0) {
								for (int j1 = 0; j1 < n; j1++) {
									button[0][j1].set_num(A[y0][x0 + j1].get_num());
									button[0][j1].set_bn(A[y0][x0 + j1].get_bn());
									button[0][j1].set_par(A[y0][x0 + j1].get_par());
									button[0][j1].set_what(A[y0][x0 + j1].get_what());
									button[0][j1].set_check(A[y0][x0 + j1].get_check());
									int i1 = 0;
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									button[0][j1].texture1.loadFromImage(button[0][j1].image1);
									button[0][j1].sprite.setTexture(button[0][j1].texture1);
								}
							}			
						}	
						if (i == N - 1) {
							y0 -= 1;
							gen = 2;
							for (int j1 = 0; j1 < n; j1++) {
								for (int i1 = 0; i1 < n - 1; i1++) {
									button[i1][j1].set_bn(button[i1 + 1][j1].get_bn());
									button[i1][j1].set_num(button[i1 + 1][j1].get_num());
									button[i1][j1].set_par(button[i1 + 1][j1].get_par());
									button[i1][j1].set_what(button[i1 + 1][j1].get_what());
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									A[y0 + i1][x0 + j1].set_num(button[i1][j1].get_num());
									A[y0 + i1][x0 + j1].set_bn(button[i1][j1].get_bn());
									A[y0 + i1][x0 + j1].set_par(button[i1][j1].get_par());
									A[y0 + i1][x0 + j1].set_what(button[i1][j1].get_what());
									A[y0 + i1][x0 + j1].set_check(button[i1][j1].get_check());
									button[i1][j1].texture1.loadFromImage(button[i1][j1].image1);
									button[i1][j1].sprite.setTexture(button[i1][j1].texture1);
									//window.draw(button[i][j].sprite);
									//window.display();
								}
								if (A[y0 + N - 1][x0 + j1].get_check() == 0) {
									gen = 0;
								}
							}
							if (gen == 0) {
								srand(time(NULL));
								sum = 0;
								int k2 = (int) ((3) * rand1());
								cout << "*";
								while (sum != 2)
								{
									k1 = (int) ((9) * rand1());
									if (button[N - 1][k1].get_bn() != -1) {
										printf("%d\n", k1);
										sum += 1;
										button[N - 1][k1].set_bn(-1);
										button[N - 1][k1].set_check(1);
									}
								}
								for (int j1 = 0; j1 < n; j1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
									button[N - 1][j1].set_what(0);
									A[y0 + N - 1][x0 + j1].set_num(button[N - 1][j1].get_num());
									A[y0 + N - 1][x0 + j1].set_bn(button[N - 1][j1].get_bn());
									A[y0 + N - 1][x0 + j1].set_par(button[N - 1][j1].get_par());
									A[y0 + N - 1][x0 + j1].set_what(button[N - 1][j1].get_what());
									A[y0 + N - 1][x0 + j1].set_check(button[N - 1][j1].get_check());
									button[N - 1][j1].image1.loadFromFile("but.png");
									button[N - 1][j1].texture1.loadFromImage(button[N - 1][j1].image1);
									button[N - 1][j1].sprite.setTexture(button[N - 1][j1].texture1);
								}
							} if (gen != 0) {
								for (int j1 = 0; j1 < n; j1++) {
									button[N - 1][j1].set_num(A[y0 + N - 1][x0 + j1].get_num());
									button[N - 1][j1].set_bn(A[y0 + N - 1][x0 + j1].get_bn());
									button[N - 1][j1].set_par(A[y0 + N - 1][x0 + j1].get_par());
									button[N - 1][j1].set_what(A[y0 + N - 1][x0 + j1].get_what());
									button[N - 1][j1].set_check(A[y0 + N - 1][x0 + j1].get_check());
									int i1 = N - 1;
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									button[N - 1][j1].texture1.loadFromImage(button[N - 1][j1].image1);
									button[N - 1][j1].sprite.setTexture(button[N - 1][j1].texture1);
								}
							}
						}
						if (j == 0) {
							x0 += 1;
							gen = 2;
							for (int i1 = 0; i1 < n; i1++) {
								for (int j1 = n - 1; j1 >= 1; j1--) {
									button[i1][j1].set_bn(button[i1][j1 - 1].get_bn());
									button[i1][j1].set_num(button[i1][j1 - 1].get_num());
									button[i1][j1].set_par(button[i1][j1 - 1].get_par());
									button[i1][j1].set_what(button[i1][j1 - 1].get_what());
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									A[y0 + i1][x0 + j1].set_num(button[i1][j1].get_num());
									A[y0 + i1][x0 + j1].set_bn(button[i1][j1].get_bn());
									A[y0 + i1][x0 + j1].set_par(button[i1][j1].get_par());
									A[y0 + i1][x0 + j1].set_what(button[i1][j1].get_what());
									A[y0 + i1][x0 + j1].set_check(button[i1][j1].get_check());
									button[i1][j1].texture1.loadFromImage(button[i1][j1].image1);
									button[i1][j1].sprite.setTexture(button[i1][j1].texture1);
									//window.draw(button[i][j].sprite);
									//window.display();
								}
								if (A[y0 + i1][x0].get_check() == 0) {
									gen = 0;
								}
							}
							if (gen == 0) {
								srand(time(NULL));
								sum = 0;
								int k2 = (int) ((3) * rand1());
								cout << "*";
								while (sum != 2)
								{
									k1 = (int) ((9) * rand1());
									if (button[k1][0].get_bn() != -1) {
										printf("%d\n", k1);
										sum += 1;
										button[k1][0].set_bn(-1);
										button[k1][0].set_check(1);
									}
								}
								for (int i1 = 0; i1 < n; i1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
									button[i1][0].set_what(0);
									A[y0 + i1][x0].set_num(button[i1][0].get_num());
									A[y0 + i1][x0].set_bn(button[i1][0].get_bn());
									A[y0 + i1][x0].set_par(button[i1][0].get_par());
									A[y0 + i1][x0].set_what(button[i1][0].get_what());
									A[y0 + i1][x0].set_check(button[i1][0].get_check());
									button[i1][0].image1.loadFromFile("but.png");
									button[i1][0].texture1.loadFromImage(button[i1][0].image1);
									button[i1][0].sprite.setTexture(button[i1][0].texture1);
								}
							} if (gen != 0) {
								for (int i1 = 0; i1 < n; i1++) {
									button[i1][0].set_num(A[y0 + i1][x0].get_num());
									button[i1][0].set_bn(A[y0 + i1][x0].get_bn());
									button[i1][0].set_par(A[y0 + i1][x0].get_par());
									button[i1][0].set_what(A[y0 + i1][x0].get_what());
									button[i1][0].set_check(A[y0 + i1][x0].get_check());
									int j1 = 0;
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									button[i1][0].texture1.loadFromImage(button[i1][0].image1);
									button[i1][0].sprite.setTexture(button[i1][0].texture1);
								}
							}	
						}
						if (j == N - 1) {
							x0 -= 1;
							gen = 2;
							for (int i1 = 0; i1 < n; i1++) {
								for (int j1 = 0; j1 < n - 1; j1++) {
									button[i1][j1].set_bn(button[i1][j1 + 1].get_bn());
									button[i1][j1].set_num(button[i1][j1 + 1].get_num());
									button[i1][j1].set_par(button[i1][j1 + 1].get_par());
									button[i1][j1].set_what(button[i1][j1 + 1].get_what());
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									A[y0 + i1][x0 + j1].set_num(button[i1][j1].get_num());
									A[y0 + i1][x0 + j1].set_bn(button[i1][j1].get_bn());
									A[y0 + i1][x0 + j1].set_par(button[i1][j1].get_par());
									A[y0 + i1][x0 + j1].set_what(button[i1][j1].get_what());
									A[y0 + i1][x0 + j1].set_check(button[i1][j1].get_check());
									button[i1][j1].texture1.loadFromImage(button[i1][j1].image1);
									button[i1][j1].sprite.setTexture(button[i1][j1].texture1);
								}
								if (A[y0 + i1][x0 + N - 1].get_check() == 0) {
									gen = 0;
								}
							}
							if (gen == 0) {
								srand(time(NULL));
								sum = 0;
								int k2 = (int) ((3) * rand1());
								cout << "*";
								while (sum != 2)
								{
									k1 = (int) ((9) * rand1());
									if (button[k1][0].get_bn() != -1) {
										printf("%d\n", k1);
										sum += 1;
										button[k1][N - 1].set_bn(-1);
										button[k1][N - 1].set_check(1);
									}
								}
								for (int i1 = 0; i1 < n; i1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
									button[i1][N - 1].set_what(0);
									A[y0 + i1][x0 + N - 1].set_num(button[i1][N - 1].get_num());
									A[y0 + i1][x0 + N - 1].set_bn(button[i1][N - 1].get_bn());
									A[y0 + i1][x0 + N - 1].set_par(button[i1][N - 1].get_par());
									A[y0 + i1][x0 + N - 1].set_what(button[i1][N - 1].get_what());
									A[y0 + i1][x0 + N - 1].set_check(button[i1][N - 1].get_check());
									button[i1][N - 1].image1.loadFromFile("but.png");
									button[i1][N - 1].texture1.loadFromImage(button[i1][N - 1].image1);
									button[i1][N - 1].sprite.setTexture(button[i1][N - 1].texture1);
								}
							} if (gen != 0) {
								for (int i1 = 0; i1 < n; i1++) {
									button[i1][N - 1].set_num(A[y0 + i1][x0 + N - 1].get_num());
									button[i1][N - 1].set_bn(A[y0 + i1][x0 + N - 1].get_bn());
									button[i1][N - 1].set_par(A[y0 + i1][x0 + N - 1].get_par());
									button[i1][N - 1].set_what(A[y0 + i1][x0 + N - 1].get_what());
									button[i1][N - 1].set_check(A[y0 + i1][x0 + N - 1].get_check());
									int j1 = N - 1;
									if (button[i1][j1].get_what() == 1) {
										switch (button[i1][j1].get_bn()) {
											case 1:
												  button[i1][j1].image1.loadFromFile("1.png");
												  break;
											case 2:
								                                button[i1][j1].image1.loadFromFile("2.png");
								                                break;
											case 3:
								                                button[i1][j1].image1.loadFromFile("3.png");
								                                break;
											case 4:
								                                button[i1][j1].image1.loadFromFile("4.png");
								                                break;
											case 5:
								                                button[i1][j1].image1.loadFromFile("5.png");
								                                break;
											case 6:
								                                button[i1][j1].image1.loadFromFile("6.png");
								                                break;
											case 7:
								                                button[i1][j1].image1.loadFromFile("7.png");
								                                break;
											case 8:
								                                button[i1][j1].image1.loadFromFile("8.png");
								                                break;
											case 0:
												  button[i1][j1].image1.loadFromFile("0.png");
								                                break;
											case -1:
												  button[i1][j1].image1.loadFromFile("bomb.png");
								                                break;
										}
									} else if (button[i1][j1].get_what() == 2) {
										button[i1][j1].image1.loadFromFile("flag.png");
									} else if (button[i1][j1].get_what() == 0) {
										button[i1][j1].image1.loadFromFile("but.png");
									}
									button[i1][N - 1].texture1.loadFromImage(button[i1][N - 1].image1);
									button[i1][N - 1].sprite.setTexture(button[i1][N - 1].texture1);
								//window.draw(button[i][0].sprite);
								//window.display();
							}
						}
					}
	        		}
			}
		}
		if(isSpriteHover(sprite11.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
               {
                       if(event.type == sf::Event::MouseButtonReleased /*&& event.mouseButton.button == sf::Mouse::Left*/ && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                       {
                       	//printf("1");
                       	x0 -= 1;
				gen = 2;
				for (int i = 0; i < n; i++) {
                        		for (int j = n - 1; j >= 1; j--) {
                        			button[i][j].set_bn(button[i][j - 1].get_bn());
                        			button[i][j].set_num(button[i][j - 1].get_num());
                        			button[i][j].set_par(button[i][j - 1].get_par());
                        			button[i][j].set_what(button[i][j - 1].get_what());
		                		if (button[i][j].get_what() == 1) {
		                			switch (button[i][j].get_bn()) {
								case 1:
									  button[i][j].image1.loadFromFile("1.png");
									  break;
								case 2:
		                                                        button[i][j].image1.loadFromFile("2.png");
		                                                        break;
								case 3:
		                                                        button[i][j].image1.loadFromFile("3.png");
		                                                        break;
								case 4:
		                                                        button[i][j].image1.loadFromFile("4.png");
		                                                        break;
								case 5:
		                                                        button[i][j].image1.loadFromFile("5.png");
		                                                        break;
								case 6:
		                                                        button[i][j].image1.loadFromFile("6.png");
		                                                        break;
								case 7:
		                                                        button[i][j].image1.loadFromFile("7.png");
		                                                        break;
								case 8:
		                                                        button[i][j].image1.loadFromFile("8.png");
		                                                        break;
								case 0:
									  button[i][j].image1.loadFromFile("0.png");
		                                                        break;
								case -1:
									  button[i][j].image1.loadFromFile("bomb.png");
		                                                        break;
							}
						} else if (button[i][j].get_what() == 2) {
							button[i][j].image1.loadFromFile("flag.png");
						} else if (button[i][j].get_what() == 0) {
							button[i][j].image1.loadFromFile("but.png");
						}
						A[y0 + i][x0 + j].set_num(button[i][j].get_num());
						A[y0 + i][x0 + j].set_bn(button[i][j].get_bn());
						A[y0 + i][x0 + j].set_par(button[i][j].get_par());
						A[y0 + i][x0 + j].set_what(button[i][j].get_what());
						A[y0 + i][x0 + j].set_check(button[i][j].get_check());
						button[i][j].texture1.loadFromImage(button[i][j].image1);
						button[i][j].sprite.setTexture(button[i][j].texture1);
						//window.draw(button[i][j].sprite);
						//window.display();
		            		}
					if (A[y0 + i][x0].get_check() == 0) {
						gen = 0;
					}
			}
			if (gen == 0) {
				srand(time(NULL));
				sum = 0;
				int k2 = (int) ((3) * rand1());
				cout << "*";
				while (sum != 2)
				{
					k1 = (int) ((9) * rand1());
					if (button[k1][0].get_bn() != -1) {
						printf("%d\n", k1);
						sum += 1;
						button[k1][0].set_bn(-1);
						button[k1][0].set_check(1);
					}
				}
				for (int i1 = 0; i1 < n; i1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
					button[i1][0].set_what(0);
					A[y0 + i1][x0].set_num(button[i1][0].get_num());
					A[y0 + i1][x0].set_bn(button[i1][0].get_bn());
					A[y0 + i1][x0].set_par(button[i1][0].get_par());
					A[y0 + i1][x0].set_what(button[i1][0].get_what());
					A[y0 + i1][x0].set_check(button[i1][0].get_check());
					button[i1][0].image1.loadFromFile("but.png");
					button[i1][0].texture1.loadFromImage(button[i1][0].image1);
					button[i1][0].sprite.setTexture(button[i1][0].texture1);
				}
			} if (gen != 0) {
				for (int i1 = 0; i1 < n; i1++) {
					button[i1][0].set_num(A[y0 + i1][x0].get_num());
					button[i1][0].set_bn(A[y0 + i1][x0].get_bn());
					button[i1][0].set_par(A[y0 + i1][x0].get_par());
					button[i1][0].set_what(A[y0 + i1][x0].get_what());
					button[i1][0].set_check(A[y0 + i1][x0].get_check());
					int j1 = 0;
					if (button[i1][j1].get_what() == 1) {
						switch (button[i1][j1].get_bn()) {
							case 1:
								  button[i1][j1].image1.loadFromFile("1.png");
								  break;
							case 2:
				                                button[i1][j1].image1.loadFromFile("2.png");
				                                break;
							case 3:
				                                button[i1][j1].image1.loadFromFile("3.png");
				                                break;
							case 4:
				                                button[i1][j1].image1.loadFromFile("4.png");
				                                break;
							case 5:
				                                button[i1][j1].image1.loadFromFile("5.png");
				                                break;
							case 6:
				                                button[i1][j1].image1.loadFromFile("6.png");
				                                break;
							case 7:
				                                button[i1][j1].image1.loadFromFile("7.png");
				                                break;
							case 8:
				                                button[i1][j1].image1.loadFromFile("8.png");
				                                break;
							case 0:
								  button[i1][j1].image1.loadFromFile("0.png");
				                                break;
							case -1:
								  button[i1][j1].image1.loadFromFile("bomb.png");
				                                break;
						}
					} else if (button[i1][j1].get_what() == 2) {
						button[i1][j1].image1.loadFromFile("flag.png");
					} else if (button[i1][j1].get_what() == 0) {
						button[i1][j1].image1.loadFromFile("but.png");
					}
					button[i1][0].texture1.loadFromImage(button[i1][0].image1);
					button[i1][0].sprite.setTexture(button[i1][0].texture1);
				}
			}	
		} }
		if(isSpriteHover(sprite2.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
               {
                       if(event.type == sf::Event::MouseButtonReleased /*&& event.mouseButton.button == sf::Mouse::Left*/ && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                       {
                       	x0 += 1;
				gen = 2;
				for (int i = 0; i < n; i++) {
                        		for (int j = 0; j < n - 1; j++) {
                        			button[i][j].set_bn(button[i][j + 1].get_bn());
                        			button[i][j].set_num(button[i][j + 1].get_num());
                        			button[i][j].set_par(button[i][j + 1].get_par());
                        			button[i][j].set_what(button[i][j + 1].get_what());
		                		if (button[i][j].get_what() == 1) {
		                			switch (button[i][j].get_bn()) {
								case 1:
									  button[i][j].image1.loadFromFile("1.png");
									  break;
								case 2:
		                                                        button[i][j].image1.loadFromFile("2.png");
		                                                        break;
								case 3:
		                                                        button[i][j].image1.loadFromFile("3.png");
		                                                        break;
								case 4:
		                                                        button[i][j].image1.loadFromFile("4.png");
		                                                        break;
								case 5:
		                                                        button[i][j].image1.loadFromFile("5.png");
		                                                        break;
								case 6:
		                                                        button[i][j].image1.loadFromFile("6.png");
		                                                        break;
								case 7:
		                                                        button[i][j].image1.loadFromFile("7.png");
		                                                        break;
								case 8:
		                                                        button[i][j].image1.loadFromFile("8.png");
		                                                        break;
								case 0:
									  button[i][j].image1.loadFromFile("0.png");
		                                                        break;
								case -1:
									  button[i][j].image1.loadFromFile("bomb.png");
		                                                        break;
							}
						} else if (button[i][j].get_what() == 2) {
							button[i][j].image1.loadFromFile("flag.png");
						} else if (button[i][j].get_what() == 0) {
							button[i][j].image1.loadFromFile("but.png");
						}
						A[y0 + i][x0 + j].set_num(button[i][j].get_num());
						A[y0 + i][x0 + j].set_bn(button[i][j].get_bn());
						A[y0 + i][x0 + j].set_par(button[i][j].get_par());
						A[y0 + i][x0 + j].set_what(button[i][j].get_what());
						A[y0 + i][x0 + j].set_check(button[i][j].get_check());
						button[i][j].texture1.loadFromImage(button[i][j].image1);
						button[i][j].sprite.setTexture(button[i][j].texture1);
					}
					if (A[y0 + i][x0 + N - 1].get_check() == 0) {
						gen = 0;
					}
				}
				if (gen == 0) {
				srand(time(NULL));
				sum = 0;
				int k2 = (int) ((3) * rand1());
				cout << "*";
				while (sum != 2)
				{
					k1 = (int) ((9) * rand1());
					if (button[k1][0].get_bn() != -1) {
						printf("%d\n", k1);
						sum += 1;
						button[k1][N - 1].set_bn(-1);
						button[k1][N - 1].set_check(1);
					}
				}
				for (int i1 = 0; i1 < n; i1++) {	//вот здесь создается новый столбей/строка, изменить параметры на новые
					button[i1][N - 1].set_what(0);
					A[y0 + i1][x0 + N - 1].set_num(button[i1][N - 1].get_num());
					A[y0 + i1][x0 + N - 1].set_bn(button[i1][N - 1].get_bn());
					A[y0 + i1][x0 + N - 1].set_par(button[i1][N - 1].get_par());
					A[y0 + i1][x0 + N - 1].set_what(button[i1][N - 1].get_what());
					A[y0 + i1][x0 + N - 1].set_check(button[i1][N - 1].get_check());
					button[i1][N - 1].image1.loadFromFile("but.png");
					button[i1][N - 1].texture1.loadFromImage(button[i1][N - 1].image1);
					button[i1][N - 1].sprite.setTexture(button[i1][N - 1].texture1);
				}
			} if (gen != 0) {
				cout << "!";
				for (int i1 = 0; i1 < n; i1++) {
					button[i1][N - 1].set_num(A[y0 + i1][x0 + N - 1].get_num());
					button[i1][N - 1].set_bn(A[y0 + i1][x0 + N - 1].get_bn());
					button[i1][N - 1].set_par(A[y0 + i1][x0 + N - 1].get_par());
					button[i1][N - 1].set_what(A[y0 + i1][x0 + N - 1].get_what());
					button[i1][N - 1].set_check(A[y0 + i1][x0 + N - 1].get_check());
					int j1 = N - 1;
					if (button[i1][j1].get_what() == 1) {
						switch (button[i1][j1].get_bn()) {
							case 1:
								  button[i1][j1].image1.loadFromFile("1.png");
								  break;
							case 2:
				                                button[i1][j1].image1.loadFromFile("2.png");
				                                break;
							case 3:
				                                button[i1][j1].image1.loadFromFile("3.png");
				                                break;
							case 4:
				                                button[i1][j1].image1.loadFromFile("4.png");
				                                break;
							case 5:
				                                button[i1][j1].image1.loadFromFile("5.png");
				                                break;
							case 6:
				                                button[i1][j1].image1.loadFromFile("6.png");
				                                break;
							case 7:
				                                button[i1][j1].image1.loadFromFile("7.png");
				                                break;
							case 8:
				                                button[i1][j1].image1.loadFromFile("8.png");
				                                break;
							case 0:
								  button[i1][j1].image1.loadFromFile("0.png");
				                                break;
							case -1:
								  button[i1][j1].image1.loadFromFile("bomb.png");
				                                break;
						}
					} else if (button[i1][j1].get_what() == 2) {
						button[i1][j1].image1.loadFromFile("flag.png");
					} else if (button[i1][j1].get_what() == 0) {
						button[i1][j1].image1.loadFromFile("but.png");
					}
					button[i1][N - 1].texture1.loadFromImage(button[i1][N - 1].image1);
					button[i1][N - 1].sprite.setTexture(button[i1][N - 1].texture1);
					//window.draw(button[i][0].sprite);
					//window.display();
		                }
		         }												
		} }
		if(isSpriteHover(sprite3.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
               {
                       if(event.type == sf::Event::MouseButtonReleased /*&& event.mouseButton.button == sf::Mouse::Left*/ && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                       {
                       	//printf("3");
				for (int j = 0; j < n; j++) {
                        		for (int i = n - 1; i >= 1; i--) {
                        			button[i][j].set_bn(button[i - 1][j].get_bn());
                        			button[i][j].set_num(button[i - 1][j].get_num());
                        			button[i][j].set_par(button[i - 1][j].get_par());
                        			button[i][j].set_what(button[i - 1][j].get_what());
		                		if (button[i][j].get_what() == 1) {
		                			switch (button[i][j].get_bn()) {
								case 1:
									  button[i][j].image1.loadFromFile("1.png");
									  break;
								case 2:
		                                                        button[i][j].image1.loadFromFile("2.png");
		                                                        break;
								case 3:
		                                                        button[i][j].image1.loadFromFile("3.png");
		                                                        break;
								case 4:
		                                                        button[i][j].image1.loadFromFile("4.png");
		                                                        break;
								case 5:
		                                                        button[i][j].image1.loadFromFile("5.png");
		                                                        break;
								case 6:
		                                                        button[i][j].image1.loadFromFile("6.png");
		                                                        break;
								case 7:
		                                                        button[i][j].image1.loadFromFile("7.png");
		                                                        break;
								case 8:
		                                                        button[i][j].image1.loadFromFile("8.png");
		                                                        break;
								case 0:
									  button[i][j].image1.loadFromFile("0.png");
		                                                        break;
								case -1:
									  button[i][j].image1.loadFromFile("bomb.png");
		                                                        break;
							}
						} else if (button[i][j].get_what() == 2) {
							button[i][j].image1.loadFromFile("flag.png");
						} else if (button[i][j].get_what() == 0) {
							button[i][j].image1.loadFromFile("but.png");
						}
						button[i][j].texture1.loadFromImage(button[i][j].image1);
						button[i][j].sprite.setTexture(button[i][j].texture1);
						//window.draw(button[i][j].sprite);
						//window.display();
		                	}
		                	//вот здесь создается новый столбей/строка, изменить параметры на новые
		                	button[0][j].image1.loadFromFile("but.png");
		                	button[0][j].set_bn(0);
		                	button[0][j].set_num(0);
		                	button[0][j].set_par(0);
		                	button[0][j].set_what(0);
		                	button[0][j].texture1.loadFromImage(button[0][j].image1);
					button[0][j].sprite.setTexture(button[0][j].texture1);
					//window.draw(button[i][0].sprite);
					//window.display();
		                }
		         }												
		}
		if(isSpriteHover(sprite4.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
               {
                       if(event.type == sf::Event::MouseButtonReleased /*&& event.mouseButton.button == sf::Mouse::Left*/ && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                       {
                       	//printf("4");
				for (int j = 0; j < n; j++) {
                        		for (int i = 0; i < n - 1; i++) {
                        			button[i][j].set_bn(button[i + 1][j].get_bn());
                        			button[i][j].set_num(button[i + 1][j].get_num());
                        			button[i][j].set_par(button[i + 1][j].get_par());
                        			button[i][j].set_what(button[i + 1][j].get_what());
		                		if (button[i][j].get_what() == 1) {
		                			switch (button[i][j].get_bn()) {
								case 1:
									  button[i][j].image1.loadFromFile("1.png");
									  break;
								case 2:
		                                                        button[i][j].image1.loadFromFile("2.png");
		                                                        break;
								case 3:
		                                                        button[i][j].image1.loadFromFile("3.png");
		                                                        break;
								case 4:
		                                                        button[i][j].image1.loadFromFile("4.png");
		                                                        break;
								case 5:
		                                                        button[i][j].image1.loadFromFile("5.png");
		                                                        break;
								case 6:
		                                                        button[i][j].image1.loadFromFile("6.png");
		                                                        break;
								case 7:
		                                                        button[i][j].image1.loadFromFile("7.png");
		                                                        break;
								case 8:
		                                                        button[i][j].image1.loadFromFile("8.png");
		                                                        break;
								case 0:
									  button[i][j].image1.loadFromFile("0.png");
		                                                        break;
								case -1:
									  button[i][j].image1.loadFromFile("bomb.png");
		                                                        break;
							}
						} else if (button[i][j].get_what() == 2) {
							button[i][j].image1.loadFromFile("flag.png");
						} else if (button[i][j].get_what() == 0) {
							button[i][j].image1.loadFromFile("but.png");
						}
						button[i][j].texture1.loadFromImage(button[i][j].image1);
						button[i][j].sprite.setTexture(button[i][j].texture1);
						//window.draw(button[i][j].sprite);
						//window.display();
		                	}
		                	//вот здесь создается новый столбей/строка, изменить параметры на новые
		                	button[n - 1][j].image1.loadFromFile("but.png");
		                	button[n - 1][j].set_bn(0);
		                	button[n - 1][j].set_num(0);
		                	button[n - 1][j].set_par(0);
		                	button[n - 1][j].set_what(0);
		                	button[n - 1][j].texture1.loadFromImage(button[n - 1][j].image1);
					button[n - 1][j].sprite.setTexture(button[n - 1][j].texture1);
					//window.draw(button[i][0].sprite);
					//window.display();
		                }
		         }												
		}
		window.clear(sf::Color::White);
		window.draw(text);
		for (int i = 0; i < n; i++) {
                	for (int j = 0; j < n; j++) {
				window.draw(button[i][j].sprite);
			}
		}
		window.draw(sprite11);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
    		window.display();
    	} }
    	free(A);
        return;
}

int main()
{       
	menu();
	struct tm *u;
	char *f;
	//system("chcp 1251");
	//system("cls");
	const time_t timer = time(NULL);
	u = localtime(&timer);
	f = settime(u);
	puts(f);
	return 0;
}
//большой массив, координаты маленького массива в большом, генерация бомб при сдвиге, заполнение постепенное массива get_what, переписывание из большого массива в маленький по координате левого верхнего угла, подумать (2 варианта): 1) изначально маленький массив в середине большого; 2) (0,0) маленького и большого совпадают, но тогда как считать координаты левого верхнего угла при сдвиге вверх и влево, презентация (КРИНЖ) 
//таблица достижений, при сдвиге все сохраняется (расширяется массив)
