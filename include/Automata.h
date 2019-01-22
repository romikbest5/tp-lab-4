#ifndef CLASS_AUTOMATA_h
#define CLASS_AUTOMATA_h
//#pragma once

#define MAX_AMOUNT 8

#include <string>
#include <iostream>

using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };//��������� ��������� ��������
class Automata
{
private:
	/*===== [����������] =====*/
	STATES state;				//������� ��������� ��������
	int cash;					//����� ����� � ��������
	string menu[MAX_AMOUNT];	//������ ����� �������� ��������
	int prices[MAX_AMOUNT];		//������ ��� ��������

	int choosen_drink;			//ID ���������� ������� �������������
	short int checked_status;	//��������� �������� (0 - ������������ �����; 1 - �����; -1 - ������ �������� ���������)

public:
	/*===== [������] =====*/
	Automata();//�����������
	bool on();				//��������� ��������
	bool off();				//���������� ��������
	int coin(int);			//��������� ����� �� ���� �������������
	void printMenu();		//����������� ���� � ��������� � ������ ��� ������������
	string printState();	//����������� �������� ��������� ��� ������������
	string choice(int);		//����� ������� �������������
	int check(int);			//�������� ������� ����������� �����
	int cancel();			//������ ������ ������������ �������������
	int cook();			//�������� �������� ������������� �������
	int finish();			//���������� ������������ ������������.
};

#endif