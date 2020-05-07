#ifndef __BASE_H // Make sure to only declare these classes once
#define __BASE_H
class MainApp : public wxApp // MainApp is the class for our application
{
    // MainApp just acts as a container for the window,
public: // or frame in MainFrame
    virtual bool OnInit();
};

class MainFrame : public wxFrame // MainFrame is the class for our window,
{
    // It contains the window and all objects in it
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxButton* LetsGo;
    wxButton* Exit;
    void OnExit(wxCommandEvent& event);
    void OnGo(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

enum
{
    BUTTON_Go = wxID_HIGHEST + 1,
    BUTTON_Exit = wxID_HIGHEST + 1,
    TEXT_Start = wxID_HIGHEST + 1

};
#endif
