#include <wx/wx.h>
#include <cmath>
#include <iostream>
#include <wx/spinctrl.h>
#include "resource.h"

int grArray[20];
int runeGrant[20] = { 200,400,800,1200,1600,2000,2500,3000,3800,5000,6250,7500,10000,12500,15000,20000,25000,30000,35000,50000 };
wxString grArrayDisp;

class App : public wxApp {
public:
    bool OnInit() {

        int windowWidth = 550;
        int windowLength = 650;
        int defaultFont = 10;
        int largeFont = 16;
        int smallFont = 8;

        wxSizerFlags::DisableConsistencyChecks();
        wxFrame* window = new wxFrame(NULL, wxID_ANY, "Elden Ring Rune Calculator (ERRP)", wxDefaultPosition, wxSize(windowWidth, windowLength));
        
        //Creating the sizers for organizing
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        wxBoxSizer* runeHelpSizer = new wxBoxSizer(wxVERTICAL);

        wxBoxSizer* lvlTextSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* grTextSizer = new wxBoxSizer(wxVERTICAL);

        wxBoxSizer* lvlInputSizer = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer* grInputSizer = new wxBoxSizer(wxVERTICAL);

        wxBoxSizer* grButtons = new wxBoxSizer(wxHORIZONTAL);

        wxBoxSizer* resultSizer = new wxBoxSizer(wxHORIZONTAL);

        wxBoxSizer* preCalcSizer = new wxBoxSizer(wxHORIZONTAL);

        wxStaticText* runeHelp = new wxStaticText(window, wxID_ANY, "*Numen: 14, Hero 1: 15, Hero 2: 16, Hero 3: 17, \nHero 4: 18, Hero 5: 19, Lord: 20*", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        runeHelp->SetFont(wxFont(smallFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        runeHelpSizer->Add(runeHelp, 0, wxALIGN_CENTER | wxTOP | wxRIGHT, 20);

        //Text for current level and its input
        wxStaticText* currentLvl = new wxStaticText(window, wxID_ANY, "Your current level:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        currentLvl->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        wxSpinCtrl* inputLvl = new wxSpinCtrl(window, wxID_ANY, "40", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputLvl->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        //Putting the previous items on the horizontal plain
        lvlTextSizer->Add(currentLvl, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        lvlInputSizer->Add(inputLvl, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 25);;

        //How many levels and its input
        wxStaticText* lvlUp = new wxStaticText(window, wxID_ANY, "How many levels ups:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        lvlUp->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        wxSpinCtrl* inputNumLvl = new wxSpinCtrl(window, wxID_ANY, "3", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputNumLvl->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        //Putting the previous items on the horizontal plain
        lvlTextSizer->Add(lvlUp, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        lvlInputSizer->Add(inputNumLvl, 0, wxLEFT | wxTOP | wxALIGN_LEFT, 25);

        //Input for level of golden rune and its input
        wxStaticText* lvlGR = new wxStaticText(window, wxID_ANY, "Level of Golden Rune:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        lvlGR->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        wxSpinCtrl* inputlvlGR = new wxSpinCtrl(window, wxID_ANY, "7", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputlvlGR->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        //Putting the previous items on the horizontal plain
        grTextSizer->Add(lvlGR, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        grInputSizer->Add(inputlvlGR, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 25);

        //Amount of golden rune and its input
        wxStaticText* numGR = new wxStaticText(window, wxID_ANY, "Amount of that Golden Rune:", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        numGR->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        wxSpinCtrl* inputnumGR = new wxSpinCtrl(window, wxID_ANY, "3", wxDefaultPosition, wxDefaultSize, wxTE_CENTER);
        inputnumGR->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        //Putting the previous items on the horizontal plain
        grTextSizer->Add(numGR, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        grInputSizer->Add(inputnumGR, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 25);

        // Add button to perform calculation
        wxButton* calculateButton = new wxButton(window, wxID_ANY, "Calculate");
        lvlTextSizer->Add(calculateButton, 0, wxALIGN_CENTER | wxTOP, 40);

        wxButton* addButton = new wxButton(window, wxID_ANY, "Add");
        grButtons->Add(addButton, 0, wxALIGN_LEFT | wxLEFT, 30);

        wxButton* clearButton = new wxButton(window, wxID_ANY, "Clear");
        grButtons->Add(clearButton);

        // Add static text to display result
        wxStaticText* resultText = new wxStaticText(window, wxID_ANY, "",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        resultText->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        

        wxStaticText* runeCostText = new wxStaticText(window, wxID_ANY, "",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        runeCostText->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

        wxStaticText* grAmount = new wxStaticText(window, wxID_ANY, "",
            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
        grAmount->SetFont(wxFont(defaultFont, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
        
        wxString grTextArray;
        for (int i = 0; i < 20; i++) {
            if (i == 13)
                grTextArray += wxString::Format("Numen's Runes: %d\n", grArray[i]);
            else if (i > 13 && i < 19)
                grTextArray += wxString::Format("Hero Rune %d: %d\n", i - 13, grArray[i]);
            else if (i == 19)
                grTextArray += wxString::Format("Lord's Rune: %d\n", grArray[i]);
            else
                grTextArray += wxString::Format("Golden Rune[%d]: %d\n", i + 1, grArray[i]);
        }
        grAmount->SetLabelText(wxString::Format("%s", grTextArray));

        grTextSizer->Add(grButtons, 0, wxALIGN_CENTER | wxTOP, 40);

        lvlTextSizer->Add(resultText, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        lvlTextSizer->Add(runeCostText, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);
        grTextSizer->Add(grAmount, 0, wxALIGN_CENTER | wxTOP | wxLEFT, 30);

        preCalcSizer->Add(lvlTextSizer);
        preCalcSizer->Add(lvlInputSizer);
        preCalcSizer->Add(grTextSizer);
        preCalcSizer->Add(grInputSizer);

        sizer->Add(runeHelpSizer, 0, wxALIGN_RIGHT);
        sizer->Add(preCalcSizer, 0, wxALIGN_LEFT);

        //sizer->Add(resultSizer, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30); // Add the rune cost text to the sizer
        //sizer->Add(resultText, 0, wxALIGN_LEFT | wxTOP | wxLEFT, 30);

        // Bind button click event to perform calculation
        addButton->Bind(wxEVT_BUTTON, [inputlvlGR, inputnumGR, grAmount](wxCommandEvent& event) {
            int grlvl = inputlvlGR->GetValue() - 1;
            int numgr = inputnumGR->GetValue();
            grArray[grlvl] = grArray[grlvl] + numgr;
            wxString grTextArray;
            for (int i = 0; i < 20; i++) {
                if (i == 13)
                    grTextArray += wxString::Format("Numen's Runes: %d\n", grArray[i]);
                else if (i > 13 && i < 19)
                    grTextArray += wxString::Format("Hero Rune %d: %d\n", i - 13, grArray[i]);
                else if (i == 19)
                    grTextArray += wxString::Format("Lord's Rune: %d\n", grArray[i]);
                else
                    grTextArray += wxString::Format("Golden Rune[%d]: %d\n", i + 1, grArray[i]);
            }
            grAmount->SetLabelText(wxString::Format("%s", grTextArray));
            });

        clearButton->Bind(wxEVT_BUTTON, [grAmount](wxCommandEvent& event) {
                wxString grTextArray;
                for (int i = 0; i < 20 ; i++) {
                    grArray[i] = 0;
                }
                for (int i = 0; i < 20; i++) {
                    if (i == 13)
                        grTextArray += wxString::Format("Numen's Runes: %d\n", grArray[i]);
                    else if (i > 13 && i < 19)
                        grTextArray += wxString::Format("Hero Rune %d: %d\n", i-13, grArray[i]);
                    else if (i == 19)
                        grTextArray += wxString::Format("Lord's Rune: %d\n", grArray[i]);
                    else
                        grTextArray += wxString::Format("Golden Rune[%d]: %d\n", i+1, grArray[i]);
                }
                grAmount->SetLabelText(wxString::Format("%s", grTextArray));
            });

        // Bind button click event to perform calculation
        calculateButton->Bind(wxEVT_BUTTON, [inputLvl, inputNumLvl, window, sizer, runeCostText, resultText](wxCommandEvent& event) {
            float lvl = inputLvl->GetValue(); // Get input value as integer
            float numlvl = inputNumLvl->GetValue(); // Get input value as integer
            wxString runeCostString;
            float totalRuneCost = 0;
            int grTotal = 0;
            int roundRuneCost = 0;

            for (int i = 0; i < 20; i++) 
                grTotal += grArray[i] * runeGrant[i];
            
            int grTotal2 = grTotal;

            for (int i = 0; i < numlvl; i++) {
                float x = ((lvl + 81) - 92) * 0.02;
                float runeCost = ((x + .1) * ((lvl + 81) * (lvl + 81))) + 1;
                totalRuneCost = totalRuneCost + runeCost;
                grTotal = grTotal - runeCost;
                if (grTotal >= 0)
                    roundRuneCost = 0;
                else {
                    roundRuneCost = abs(grTotal);
                    grTotal = 0;
                }    
                int nextlvl = lvl + 1;
                runeCostString += wxString::Format("To level %d: %d \n", nextlvl, roundRuneCost);
                lvl = lvl + 1;
            }

            runeCostText->SetLabelText(wxString::Format("Rune Cost for each level: \n %s", runeCostString));

            int result;
            int roundCost = std::round(totalRuneCost);
            if (roundCost - grTotal2 > 0)
                result = roundCost - grTotal2;
            else
                result = 0;
            resultText->SetLabelText(wxString::Format("Total Rune Cost: %d", result)); // Update result tex
            });

        window->SetSizer(sizer);
        window->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);