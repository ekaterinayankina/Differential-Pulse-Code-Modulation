#include "MyForm1.h"
#pragma once
#include<stdio.h>
#include<iostream>
#include <fstream> 
#include <assert.h>
#include "MyForm1.h"
#pragma once 
using namespace std;
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	lab1::MyForm1 form;
	Application::Run(%form);
} 

