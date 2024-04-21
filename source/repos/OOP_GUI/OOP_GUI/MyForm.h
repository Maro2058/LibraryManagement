#pragma once

namespace OOPGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:







	private: System::Windows::Forms::Panel^ Loginpanel;
	private: System::Windows::Forms::RadioButton^ studentradioButton2;
	private: System::Windows::Forms::RadioButton^ librarianradioButton;






	private: System::Windows::Forms::Button^ loginbutton;

	private: System::Windows::Forms::TextBox^ Passinput;
	private: System::Windows::Forms::TextBox^ Userinput;
	private: System::Windows::Forms::Label^ Passlabel;
	private: System::Windows::Forms::Label^ usernamelabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ LibrarianPanel;
	private: System::Windows::Forms::Panel^ Librarianpanel2;
	private: System::Windows::Forms::Label^ hellolibrarian;
	private: System::Windows::Forms::Button^ GenerateReport;

	private: System::Windows::Forms::Button^ Loanrequests;

	private: System::Windows::Forms::Button^ ManageMembers;

	private: System::Windows::Forms::Button^ UpdateBook;

	private: System::Windows::Forms::Button^ Removebook;

	private: System::Windows::Forms::Button^ Addbook;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ Memberpanal;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ Hellostudent;
	private: System::Windows::Forms::Label^ label3;






	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Loginpanel = (gcnew System::Windows::Forms::Panel());
			this->Passinput = (gcnew System::Windows::Forms::TextBox());
			this->Userinput = (gcnew System::Windows::Forms::TextBox());
			this->Passlabel = (gcnew System::Windows::Forms::Label());
			this->usernamelabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->studentradioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->librarianradioButton = (gcnew System::Windows::Forms::RadioButton());
			this->loginbutton = (gcnew System::Windows::Forms::Button());
			this->LibrarianPanel = (gcnew System::Windows::Forms::Panel());
			this->hellolibrarian = (gcnew System::Windows::Forms::Label());
			this->Librarianpanel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GenerateReport = (gcnew System::Windows::Forms::Button());
			this->Loanrequests = (gcnew System::Windows::Forms::Button());
			this->ManageMembers = (gcnew System::Windows::Forms::Button());
			this->UpdateBook = (gcnew System::Windows::Forms::Button());
			this->Removebook = (gcnew System::Windows::Forms::Button());
			this->Addbook = (gcnew System::Windows::Forms::Button());
			this->Memberpanal = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Hellostudent = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Loginpanel->SuspendLayout();
			this->LibrarianPanel->SuspendLayout();
			this->Librarianpanel2->SuspendLayout();
			this->Memberpanal->SuspendLayout();
			this->SuspendLayout();
			// 
			// Loginpanel
			// 
			this->Loginpanel->BackColor = System::Drawing::Color::Transparent;
			this->Loginpanel->Controls->Add(this->Passinput);
			this->Loginpanel->Controls->Add(this->Userinput);
			this->Loginpanel->Controls->Add(this->Passlabel);
			this->Loginpanel->Controls->Add(this->usernamelabel);
			this->Loginpanel->Controls->Add(this->label1);
			this->Loginpanel->Controls->Add(this->studentradioButton2);
			this->Loginpanel->Controls->Add(this->librarianradioButton);
			this->Loginpanel->Controls->Add(this->loginbutton);
			this->Loginpanel->Location = System::Drawing::Point(0, 3);
			this->Loginpanel->Name = L"Loginpanel";
			this->Loginpanel->Size = System::Drawing::Size(880, 500);
			this->Loginpanel->TabIndex = 8;
			this->Loginpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Loginpanel_Paint);
			// 
			// Passinput
			// 
			this->Passinput->Location = System::Drawing::Point(507, 290);
			this->Passinput->Name = L"Passinput";
			this->Passinput->Size = System::Drawing::Size(200, 22);
			this->Passinput->TabIndex = 15;
			this->Passinput->UseSystemPasswordChar = true;
			// 
			// Userinput
			// 
			this->Userinput->Location = System::Drawing::Point(507, 214);
			this->Userinput->Name = L"Userinput";
			this->Userinput->Size = System::Drawing::Size(200, 22);
			this->Userinput->TabIndex = 14;
			// 
			// Passlabel
			// 
			this->Passlabel->AutoSize = true;
			this->Passlabel->BackColor = System::Drawing::Color::Transparent;
			this->Passlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Passlabel->Location = System::Drawing::Point(503, 265);
			this->Passlabel->Name = L"Passlabel";
			this->Passlabel->Size = System::Drawing::Size(89, 22);
			this->Passlabel->TabIndex = 13;
			this->Passlabel->Text = L"Password";
			// 
			// usernamelabel
			// 
			this->usernamelabel->AutoSize = true;
			this->usernamelabel->BackColor = System::Drawing::Color::Transparent;
			this->usernamelabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernamelabel->Location = System::Drawing::Point(503, 188);
			this->usernamelabel->Name = L"usernamelabel";
			this->usernamelabel->Size = System::Drawing::Size(92, 22);
			this->usernamelabel->TabIndex = 12;
			this->usernamelabel->Text = L"Username";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(498, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(306, 54);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Library Login";
			// 
			// studentradioButton2
			// 
			this->studentradioButton2->AutoSize = true;
			this->studentradioButton2->BackColor = System::Drawing::Color::Transparent;
			this->studentradioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->studentradioButton2->Location = System::Drawing::Point(507, 397);
			this->studentradioButton2->Name = L"studentradioButton2";
			this->studentradioButton2->Size = System::Drawing::Size(87, 24);
			this->studentradioButton2->TabIndex = 10;
			this->studentradioButton2->TabStop = true;
			this->studentradioButton2->Text = L"Student";
			this->studentradioButton2->UseVisualStyleBackColor = false;
			this->studentradioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// librarianradioButton
			// 
			this->librarianradioButton->AutoSize = true;
			this->librarianradioButton->BackColor = System::Drawing::Color::Transparent;
			this->librarianradioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->librarianradioButton->Location = System::Drawing::Point(507, 367);
			this->librarianradioButton->Name = L"librarianradioButton";
			this->librarianradioButton->Size = System::Drawing::Size(96, 24);
			this->librarianradioButton->TabIndex = 9;
			this->librarianradioButton->TabStop = true;
			this->librarianradioButton->Text = L"Librarian";
			this->librarianradioButton->UseVisualStyleBackColor = false;
			// 
			// loginbutton
			// 
			this->loginbutton->Location = System::Drawing::Point(616, 380);
			this->loginbutton->Name = L"loginbutton";
			this->loginbutton->Size = System::Drawing::Size(91, 30);
			this->loginbutton->TabIndex = 8;
			this->loginbutton->Text = L"Login";
			this->loginbutton->UseVisualStyleBackColor = true;
			this->loginbutton->Click += gcnew System::EventHandler(this, &MyForm::loginbutton_Click);
			// 
			// LibrarianPanel
			// 
			this->LibrarianPanel->BackColor = System::Drawing::Color::Transparent;
			this->LibrarianPanel->Controls->Add(this->Librarianpanel2);
			this->LibrarianPanel->Controls->Add(this->hellolibrarian);
			this->LibrarianPanel->Location = System::Drawing::Point(0, 0);
			this->LibrarianPanel->Name = L"LibrarianPanel";
			this->LibrarianPanel->Size = System::Drawing::Size(880, 503);
			this->LibrarianPanel->TabIndex = 9;
			// 
			// hellolibrarian
			// 
			this->hellolibrarian->AutoSize = true;
			this->hellolibrarian->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hellolibrarian->ForeColor = System::Drawing::Color::White;
			this->hellolibrarian->Location = System::Drawing::Point(3, 9);
			this->hellolibrarian->Name = L"hellolibrarian";
			this->hellolibrarian->Size = System::Drawing::Size(223, 36);
			this->hellolibrarian->TabIndex = 0;
			this->hellolibrarian->Text = L"Hello Librarian";
			this->hellolibrarian->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// Librarianpanel2
			// 
			this->Librarianpanel2->Controls->Add(this->label2);
			this->Librarianpanel2->Controls->Add(this->GenerateReport);
			this->Librarianpanel2->Controls->Add(this->Loanrequests);
			this->Librarianpanel2->Controls->Add(this->ManageMembers);
			this->Librarianpanel2->Controls->Add(this->UpdateBook);
			this->Librarianpanel2->Controls->Add(this->Removebook);
			this->Librarianpanel2->Controls->Add(this->Addbook);
			this->Librarianpanel2->ForeColor = System::Drawing::Color::Black;
			this->Librarianpanel2->Location = System::Drawing::Point(387, 3);
			this->Librarianpanel2->Name = L"Librarianpanel2";
			this->Librarianpanel2->Size = System::Drawing::Size(493, 500);
			this->Librarianpanel2->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(162, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 36);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Main Menu";
			// 
			// GenerateReport
			// 
			this->GenerateReport->BackColor = System::Drawing::Color::DarkGray;
			this->GenerateReport->ForeColor = System::Drawing::Color::Black;
			this->GenerateReport->Location = System::Drawing::Point(141, 362);
			this->GenerateReport->Name = L"GenerateReport";
			this->GenerateReport->Size = System::Drawing::Size(212, 43);
			this->GenerateReport->TabIndex = 5;
			this->GenerateReport->Text = L"Generate Report";
			this->GenerateReport->UseVisualStyleBackColor = false;
			this->GenerateReport->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// Loanrequests
			// 
			this->Loanrequests->BackColor = System::Drawing::Color::DarkGray;
			this->Loanrequests->ForeColor = System::Drawing::Color::Black;
			this->Loanrequests->Location = System::Drawing::Point(141, 313);
			this->Loanrequests->Name = L"Loanrequests";
			this->Loanrequests->Size = System::Drawing::Size(212, 43);
			this->Loanrequests->TabIndex = 4;
			this->Loanrequests->Text = L"Loan Requests";
			this->Loanrequests->UseVisualStyleBackColor = false;
			this->Loanrequests->Click += gcnew System::EventHandler(this, &MyForm::Loanrequests_Click);
			// 
			// ManageMembers
			// 
			this->ManageMembers->BackColor = System::Drawing::Color::DarkGray;
			this->ManageMembers->ForeColor = System::Drawing::Color::Black;
			this->ManageMembers->Location = System::Drawing::Point(141, 264);
			this->ManageMembers->Name = L"ManageMembers";
			this->ManageMembers->Size = System::Drawing::Size(212, 43);
			this->ManageMembers->TabIndex = 3;
			this->ManageMembers->Text = L"Manage Members";
			this->ManageMembers->UseVisualStyleBackColor = false;
			this->ManageMembers->Click += gcnew System::EventHandler(this, &MyForm::ManageMembers_Click);
			// 
			// UpdateBook
			// 
			this->UpdateBook->BackColor = System::Drawing::Color::DarkGray;
			this->UpdateBook->ForeColor = System::Drawing::Color::Black;
			this->UpdateBook->Location = System::Drawing::Point(141, 215);
			this->UpdateBook->Name = L"UpdateBook";
			this->UpdateBook->Size = System::Drawing::Size(212, 43);
			this->UpdateBook->TabIndex = 2;
			this->UpdateBook->Text = L"Update Book";
			this->UpdateBook->UseVisualStyleBackColor = false;
			// 
			// Removebook
			// 
			this->Removebook->BackColor = System::Drawing::Color::DarkGray;
			this->Removebook->ForeColor = System::Drawing::Color::Black;
			this->Removebook->Location = System::Drawing::Point(141, 166);
			this->Removebook->Name = L"Removebook";
			this->Removebook->Size = System::Drawing::Size(212, 43);
			this->Removebook->TabIndex = 1;
			this->Removebook->Text = L"Remove Book";
			this->Removebook->UseVisualStyleBackColor = false;
			// 
			// Addbook
			// 
			this->Addbook->BackColor = System::Drawing::Color::DarkGray;
			this->Addbook->ForeColor = System::Drawing::Color::Black;
			this->Addbook->Location = System::Drawing::Point(141, 117);
			this->Addbook->Name = L"Addbook";
			this->Addbook->Size = System::Drawing::Size(212, 43);
			this->Addbook->TabIndex = 0;
			this->Addbook->Text = L"Add Book";
			this->Addbook->UseVisualStyleBackColor = false;
			// 
			// Memberpanal
			// 
			this->Memberpanal->BackColor = System::Drawing::Color::Transparent;
			this->Memberpanal->Controls->Add(this->Hellostudent);
			this->Memberpanal->Controls->Add(this->label3);
			this->Memberpanal->Controls->Add(this->button5);
			this->Memberpanal->Controls->Add(this->button4);
			this->Memberpanal->Controls->Add(this->button3);
			this->Memberpanal->Controls->Add(this->button2);
			this->Memberpanal->Controls->Add(this->button1);
			this->Memberpanal->Location = System::Drawing::Point(0, 3);
			this->Memberpanal->Name = L"Memberpanal";
			this->Memberpanal->Size = System::Drawing::Size(880, 500);
			this->Memberpanal->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkGray;
			this->button1->Location = System::Drawing::Point(528, 130);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(212, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Search Books";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkGray;
			this->button2->Location = System::Drawing::Point(528, 188);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 43);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Request Loan";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::DarkGray;
			this->button3->Location = System::Drawing::Point(528, 246);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(212, 43);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Return Book";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::DarkGray;
			this->button4->Location = System::Drawing::Point(528, 304);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(212, 43);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Due Books";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::DarkGray;
			this->button5->Location = System::Drawing::Point(528, 362);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(212, 43);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Manage Account";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// Hellostudent
			// 
			this->Hellostudent->AutoSize = true;
			this->Hellostudent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hellostudent->ForeColor = System::Drawing::Color::White;
			this->Hellostudent->Location = System::Drawing::Point(3, 6);
			this->Hellostudent->Name = L"Hellostudent";
			this->Hellostudent->Size = System::Drawing::Size(194, 36);
			this->Hellostudent->TabIndex = 5;
			this->Hellostudent->Text = L"Hello Student";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(544, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 36);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Main Menu";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(882, 503);
			this->Controls->Add(this->Loginpanel);
			this->Controls->Add(this->LibrarianPanel);
			this->Controls->Add(this->Memberpanal);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"MyForm";
			this->Text = L"Library";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Loginpanel->ResumeLayout(false);
			this->Loginpanel->PerformLayout();
			this->LibrarianPanel->ResumeLayout(false);
			this->LibrarianPanel->PerformLayout();
			this->Librarianpanel2->ResumeLayout(false);
			this->Librarianpanel2->PerformLayout();
			this->Memberpanal->ResumeLayout(false);
			this->Memberpanal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Loginpanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void loginbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	LibrarianPanel->BringToFront();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Loanrequests_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ManageMembers_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
