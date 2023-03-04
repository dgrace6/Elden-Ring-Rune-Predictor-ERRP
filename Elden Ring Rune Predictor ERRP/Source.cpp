#include <wx/wx.h>
#include <cmath>
#include <iostream>
#include <wx/spinctrl.h>



class App : public wxApp {
public:
    bool OnInit() {
        wxSizerFlags::DisableConsistencyChecks();
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "Elden Ring Rune Calculator (ERRP)", wxDefaultPosition, wxSize(600, 900));
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxStaticText* currentLvl = new wxStaticText(window, wxID_ANY, "Your current level:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        currentLvl->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        sizer->Add(currentLvl, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);

        wxSpinCtrl* inputLvl = new wxSpinCtrl(window, wxID_ANY, "40", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputLvl->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(inputLvl, 0, wxLEFT | wxALIGN_LEFT, 40);

        wxStaticText* lvlUp = new wxStaticText(window, wxID_ANY, "How many levels ups:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        lvlUp->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        sizer->Add(lvlUp, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);

        wxSpinCtrl* inputNumLvl = new wxSpinCtrl(window, wxID_ANY, "3", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputNumLvl->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(inputNumLvl, 0, wxLEFT | wxALIGN_LEFT, 40);

        // Add button to perform calculation
        wxButton* calculateButton = new wxButton(window, wxID_ANY, "Calculate");
        sizer->Add(calculateButton, 0, wxALIGN_CENTER | wxTOP, 40);

        // Add static text to display result
        wxStaticText* resultText = new wxStaticText(window, wxID_ANY, "",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        resultText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(resultText, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);

        wxStaticText* runeCostText = new wxStaticText(window, wxID_ANY, "",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        runeCostText->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        sizer->Add(runeCostText, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30); // Add the rune cost text to the sizer

        // Bind button click event to perform calculation
        calculateButton->Bind(wxEVT_BUTTON, [inputLvl, inputNumLvl, window, sizer, runeCostText, resultText](wxCommandEvent& event) {
            float lvl = inputLvl->GetValue(); // Get input value as integer
            float numlvl = inputNumLvl->GetValue(); // Get input value as integer
            wxString runeCostString;
            float totalRuneCost = 0;
            for (int i = 0; i < numlvl; i++) {
                float x = ((lvl + 81) - 92) * 0.02;
                float runeCost = ((x + .1) * ((lvl + 81) * (lvl + 81))) + 1;
                totalRuneCost = totalRuneCost + runeCost;
                int roundRuneCost = runeCost;
                int nextlvl = lvl + 1;
                runeCostString += wxString::Format("To level %d: %d \n", nextlvl, roundRuneCost);
                lvl = lvl + 1;
            }
            
            runeCostText->SetLabelText(wxString::Format("Rune Cost for each level: \n %s", runeCostString));

            int result = std::round(totalRuneCost);
            resultText->SetLabelText(wxString::Format("Total Rune Cost: %d", result)); // Update result tex
            });

        window->SetSizer(sizer);
        window->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);
