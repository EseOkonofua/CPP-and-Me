#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
/*array<String^>^*/
[STAThreadAttribute]
int Main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	FractionCalculator::MyForm form;
	Application::Run(%form);
	return 0;
}