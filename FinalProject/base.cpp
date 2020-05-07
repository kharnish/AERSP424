#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "base.h"
#include <wx/numdlg.h>
#include <wx/msgdlg.h>
#include <wx/stattext.h>
#include <wx/msgout.h>
#include <wx/textctrl.h>


IMPLEMENT_APP(MainApp) // Initializes the MainApp class and tells our program
// to run it
bool MainApp::OnInit()
{
    // Create an instance of our frame, or window
    MainFrame* MainWin = new MainFrame(_T("Hello World!"), wxPoint(1, 1), wxSize(300, 350));
    MainWin->Show(TRUE); // show the window
    SetTopWindow(MainWin); // and finally, set it as the main window


    wxTextCtrl* text = new wxTextCtrl(MainWin, TEXT_Start, "Enter your name", wxPoint(80, 150), wxDefaultSize, 0);

    return TRUE;
}

int main() {
    
    return 0;
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_Exit, MainFrame::OnExit)
    EVT_BUTTON(BUTTON_Go, MainFrame::OnGo)
    EVT_TEXT_ENTER(TEXT_Start, MainFrame::OnExit)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize
    & size) : wxFrame((wxFrame*)NULL, -1, title, pos, size)
{    
    wxStaticText* Welcome = new wxStaticText(this, TEXT_Start, "Welcome to the Penn State Trail!", wxPoint(50, 25), wxDefaultSize, 0);

    wxStaticText* Intro = new wxStaticText(this, TEXT_Start, "You have a final exam at 10:10 am tomorrow \nmorning in Forum building, a 1.0 mile walk \nfrom your apartment. Follow the instructions \non the screen to try and get there on time.", wxPoint(25, 75), wxDefaultSize, 0); 
    
    LetsGo = new wxButton(this, BUTTON_Go, _T("Let's go!"), wxPoint(100, 200), wxSize(70, 30), 0);
    Exit = new wxButton(this, BUTTON_Exit, _T("Exit"), wxPoint(100, 250), wxSize(70, 30), 0);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(TRUE); // Tells the OS to quit running this process
}

void MainFrame::OnGo(wxCommandEvent& event)
{
    int answer = wxMessageBox("Do you want to walk?", "You may not make it", wxYES_NO);
}