//Перевод
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <Windows.h>
#include <Windowsx.h>
#include <iostream>

#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

HWND translate, textout, textin, code_zone, about;

class BinChar
{
private:

	bool bit[9];

public:

	BinChar(){
		for ( int i = 0; i < 9; i++ )
			bit[i] = 0;
	}

	void recValue( char temp ){		// Записываем значение с символа
		if ( ( int )temp < 0 )
			bit[0] = 1;
		else bit[0] = 0;
		for ( int i = 8; i >= 1; i-- ){
			bit[i] = ( int )temp % 2;
			temp = ( int )temp / 2;
		}
	}

	void recValue( bool temp[] ){	// Записываем значение с двоичного кода
		for ( int i = 8; i >= 0; i-- )
			bit[i] = temp[i];
	}

	string printChar(){		// Выводим символ в двоичном представлении
		string result;
		for ( int i = 0; i < 9; i++ )
			if ( bit[i] )
				result += '1';
			else result += '0';
			return result;
	}

	char getChar(){			// Выводим символ в типе char
		int temp( 0 ), doubl( 1 );
		for ( int i = 8; i >= 1; i-- ){
			temp += bit[i] * doubl;
			doubl *= 2;
		}
		if ( bit[0] == 1 )
			return ( char )( -temp );
		else return ( char )temp;
	}

};

class Message{
private:

	string mes_into_str;
	BinChar *mes_into_bin;

	void convert_to_bin(){
		for ( int i = 0; i < mes_into_str.length(); i++ )
		{
			mes_into_bin[i].recValue( mes_into_str[i] );
		}
	}
	void convert_to_char(){
		mes_into_str.clear();
		for ( int i = 0; i < _msize( mes_into_bin ) / sizeof( mes_into_bin[0] ); i++ )
			mes_into_str += mes_into_bin[i].getChar();
	}

public:

	bool readMessage( const string &temp = "Error" ){

		mes_into_str = temp;

		for ( int i = 0; i < mes_into_str.length() - 1; i++ )
			if ( mes_into_str[i] != '0' && mes_into_str[i] != '1' ){
				cout << "Это сообщение распознанно как текст из за символа: \'" << mes_into_str[i] << ' ' << ( int )mes_into_str[i] << "\'\n";	// Reparing
				break;
			} else if ( ( mes_into_str.length() ) % 9 != 0 ){
				cout << "Это сообщение распознанно как текст из за неверной длины сообщения!\n";	// Reparing
				break;
			} else {
				cout << "Bin file\n";		// Reparing
				bool temp[9];
				const int size = mes_into_str.length() / 9;

				mes_into_bin = new BinChar[size];

				for ( int k = size - 1; k >= 0; k-- ){
					for ( int j = 8; j >= 0; j-- ){
						if ( mes_into_str[mes_into_str.length() - 1] == '1' )
							temp[j] = 1;
						else temp[j] = 0;
						mes_into_str.pop_back();
					}
					mes_into_bin[k].recValue( temp );
				}
				convert_to_char();
				return true;
			}

			mes_into_bin = new BinChar[mes_into_str.length()];
			convert_to_bin();
			return false;
	}

	bool readMessage( istream &stream ){
		//SetConsoleCP( 1251 );
		while ( !stream.eof() )
			mes_into_str += stream.get();
		mes_into_str.pop_back();
		//SetConsoleCP( 866 );

		for ( int i = 0; i < mes_into_str.length() - 1; i++ )
			if ( mes_into_str[i] != '0' && mes_into_str[i] != '1' ){
				cout << "Это сообщение распознанно как текст из за символа: \'" << mes_into_str[i] << ' ' << ( int )mes_into_str[i] << "\'\n";	// Reparing
				break;
			} else if ( ( mes_into_str.length() ) % 9 != 0 ){
				cout << "Это сообщение распознанно как текст из за неверной длины сообщения!\n";	// Reparing
				break;
			} else {
				cout << "Bin file\n";		// Reparing
				bool temp[9];
				const int size = mes_into_str.length() / 9;

				mes_into_bin = new BinChar[size];

				for ( int k = size - 1; k >= 0; k-- ){
					for ( int j = 8; j >= 0; j-- ){
						if ( mes_into_str[mes_into_str.length() - 1] == '1' )
							temp[j] = 1;
						else temp[j] = 0;
						mes_into_str.pop_back();
					}
					mes_into_bin[k].recValue( temp );
				}
				convert_to_char();
				return true;
			}

			mes_into_bin = new BinChar[mes_into_str.length()];
			convert_to_bin();
			return false;
	}

	bool readMessage( const char mass[], const int &size ){

		for ( int i = 0; i < size; i++ )
			mes_into_str += mass[i];

		for ( int i = 0; i < mes_into_str.length() - 1; i++ )
			if ( mes_into_str[i] != '0' && mes_into_str[i] != '1' ){
				cout << "Это сообщение распознанно как текст из за символа: \'" << mes_into_str[i] << ' ' << ( int )mes_into_str[i] << "\'\n";	// Reparing
				break;
			} else if ( ( mes_into_str.length() ) % 9 != 0 ){
				cout << "Это сообщение распознанно как текст из за неверной длины сообщения!\n";	// Reparing
				break;
			} else {
				cout << "Bin file\n";		// Reparing
				bool temp[9];
				const int size = mes_into_str.length() / 9;

				mes_into_bin = new BinChar[size];

				for ( int k = size - 1; k >= 0; k-- ){
					for ( int j = 8; j >= 0; j-- ){
						if ( mes_into_str[mes_into_str.length() - 1] == '1' )
							temp[j] = 1;
						else temp[j] = 0;
						mes_into_str.pop_back();
					}
					mes_into_bin[k].recValue( temp );
				}
				convert_to_char();
				return true;
			}

			mes_into_bin = new BinChar[mes_into_str.length()];
			convert_to_bin();
			return false;
	}

	void printMesString( ostream &stream ){
		//SetConsoleCP( 1251 );
		stream << mes_into_str << endl;
		//SetConsoleCP( 866 );
	}

	void printMesBin( ostream &stream ){
		//SetConsoleCP( 1251 );
		for ( int i = 0; i < mes_into_str.length(); i++ ){
			stream << mes_into_bin[i].printChar();
		}
		//SetConsoleCP( 866 );
	}

	string getMesString(){
		return mes_into_str;
	}

	string getMesBin(){
		string temp;
		for ( int i = 0; i < mes_into_str.length(); i++ ){
			temp += mes_into_bin[i].printChar();
		}
		return temp;
	}

	void crypt( const int &code ){
		for ( int i = 0; i < mes_into_str.length(); i++ )
			mes_into_str[i] += code;
		convert_to_bin();
	}

	~Message(){
		delete[] mes_into_bin;
	}

};

BOOL	APIENTRY	About( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch ( uMsg )
	{
		case WM_COMMAND:
			switch ( LOWORD( wParam ) )
			{
				case IDOK:
					EndDialog( hWnd, wParam );
					return TRUE;
			}
	}
	return FALSE;
}
LRESULT CALLBACK WinProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch ( uMsg )
	{
		case WM_DESTROY:
			PostQuitMessage( 0 );
			return 0;
		case WM_CREATE:
			return 0;
		case WM_COMMAND:
			//Кнопка:
			if ( ( HWND )lParam == translate ){
				int size = Edit_GetTextLength( textin ) + 1;
				char *In, *Out, keyIn[10];
				static Message mesg;
				string temp;
				long long int key = 0;
				bool flag;
				In = new char[size];

				GetWindowText( textin, In, size );
				GetWindowText( code_zone, keyIn, 10 );

				key = atof( keyIn );

				for ( int i = 0; i < size; i++ ){		// Перевод из char -> string
					temp += In[i];
				}
				temp.pop_back();

				flag = mesg.readMessage( temp );	// Метод readMessage() возвращает bool, если 1 - на входе двоичный код, 0 - на входе строка

				if ( flag == 1 )				// При 1 - расшифровывваем, 0 - зашифровываем
					mesg.crypt( key );
				else mesg.crypt( -key );

				if ( flag == true ){				// Определяем тип строки на вывод
					temp = mesg.getMesString();
				} else {
					temp = mesg.getMesBin();
				}

				Out = new char[temp.length() + 1];	// Создаем массив на выход

				for ( int i = 0; i < temp.length(); i++ ){	// Переводим массив на выход string -> char
					Out[i] = temp[i];
				}

				Out[temp.length()] = '\0';		// Добавляем в конец символ конца строки

				SetWindowText( textout, Out );

				delete In;
				delete Out;
			}
			//Меню:
			switch ( LOWORD( wParam ) )
			{
				case IDM_EXIT:
					DestroyWindow( hWnd );
					return 0;
			//About
				case IDM_ABOUT:
					DialogBox( ( HINSTANCE )GetWindowLong( hWnd, GWL_HINSTANCE ), "Settings", hWnd, About );
					UpdateWindow( hWnd );
					break;
					
			}
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}
int WINAPI       WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstanse, LPSTR lpCmdLine, int nCmdShow )
{
	WNDCLASS wc;
	HWND     hWnd, text;
	MSG      msg;
	PSTR     szClassName = "SimpleWindow";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WinProc;
	wc.hInstance = hInstance;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = LoadIcon( hInstance, "IconForRun" );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground = ( HBRUSH )GetStockObject( WHITE_BRUSH );
	wc.lpszMenuName = "Menu";
	wc.lpszClassName = "SimpleWindows";
	RegisterClass( &wc );
	hWnd = CreateWindow( "SimpleWindows", "Encryption", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 100, 20, 600, 700, HWND_DESKTOP, NULL, hInstance, NULL );

	textin = CreateWindow( "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL, 10, 30, 550, 250, hWnd, 0, hInstance, 0 );
	text = CreateWindow( "STATIC", "Input text:", WS_CHILD | WS_VISIBLE, 10, 5, 550, 20, hWnd, 0, hInstance, 0 );
	textout = CreateWindow( "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | ES_READONLY, 10, 310, 550, 250, hWnd, 0, hInstance, 0 );
	text = CreateWindow( "STATIC", "Output text:", WS_CHILD | WS_VISIBLE, 10, 285, 550, 20, hWnd, 0, hInstance, 0 );
	translate = CreateWindow( "BUTTON", "Translate", WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 585, 85, 28, hWnd, 0, hInstance, 0 );
	text = CreateWindow( "STATIC", "Key:", WS_CHILD | WS_VISIBLE, 455, 584, 100, 16, hWnd, 0, hInstance, 0 );
	code_zone = CreateWindow( "EDIT", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER | ES_MULTILINE, 490, 585, 85, 16, hWnd, 0, hInstance, 0 );

	ShowWindow( hWnd, nCmdShow );
	UpdateWindow( hWnd );
	while ( GetMessage( &msg, ( HWND )NULL, 0, 0 ) )
	{
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}
	return msg.wParam;
}