// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

//
// NumberPad.xaml.cpp
// Implementation of the NumberPad class
//

#include "pch.h"
#include "NumberPad.xaml.h"
#include "Controls/CalculatorButton.h"
#include "CalcViewModel/StandardCalculatorViewModel.h"
#include "CalcViewModel/Common/LocalizationSettings.h"

using namespace CalculatorApp;
using namespace CalculatorApp::ViewModel;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace CalculatorApp::Common;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

DEPENDENCY_PROPERTY_INITIALIZATION(NumberPad, ButtonStyle);
DEPENDENCY_PROPERTY_INITIALIZATION(NumberPad, CurrentRadixType);

bool visit[10];
int ranNum[10];
int getRandomNumber(int min, int max)
{
    static const double fraction =
        1.0 / (RAND_MAX + 1.0);
 return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
void NumberPad::SetTheButton(int target, int Loc)
{
    if (Loc == 0)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 3);
            this->Root->SetColumn(this->Num0Button, 1);
        case 1:
            this->Root->SetRow(this->Num1Button, 3);
            this->Root->SetColumn(this->Num1Button, 1);
        case 2:
            this->Root->SetRow(this->Num2Button, 3);
            this->Root->SetColumn(this->Num2Button, 1);
        case 3:
            this->Root->SetRow(this->Num3Button, 3);
            this->Root->SetColumn(this->Num3Button, 1);
        case 4:
            this->Root->SetRow(this->Num4Button, 3);
            this->Root->SetColumn(this->Num4Button, 1);
        case 5:
            this->Root->SetRow(this->Num5Button, 3);
            this->Root->SetColumn(this->Num5Button, 1);
        case 6:
            this->Root->SetRow(this->Num6Button, 3);
            this->Root->SetColumn(this->Num6Button, 1);
        case 7:
            this->Root->SetRow(this->Num7Button, 3);
            this->Root->SetColumn(this->Num7Button, 1);
        case 8:
            this->Root->SetRow(this->Num8Button, 3);
            this->Root->SetColumn(this->Num8Button, 1);
        case 9:
            this->Root->SetRow(this->Num9Button, 3);
            this->Root->SetColumn(this->Num9Button, 1);
        default:
            break;
        }
    }
    else if (Loc == 1)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 2);
            this->Root->SetColumn(this->Num0Button, 0);
        case 1:
            this->Root->SetRow(this->Num1Button, 2);
            this->Root->SetColumn(this->Num1Button, 0);
        case 2:
            this->Root->SetRow(this->Num2Button, 2);
            this->Root->SetColumn(this->Num2Button, 0);
        case 3:
            this->Root->SetRow(this->Num3Button, 2);
            this->Root->SetColumn(this->Num3Button, 0);
        case 4:
            this->Root->SetRow(this->Num4Button, 2);
            this->Root->SetColumn(this->Num4Button, 0);
        case 5:
            this->Root->SetRow(this->Num5Button, 2);
            this->Root->SetColumn(this->Num5Button, 0);
        case 6:
            this->Root->SetRow(this->Num6Button, 2);
            this->Root->SetColumn(this->Num6Button, 0);
        case 7:
            this->Root->SetRow(this->Num7Button, 2);
            this->Root->SetColumn(this->Num7Button, 0);
        case 8:
            this->Root->SetRow(this->Num8Button, 2);
            this->Root->SetColumn(this->Num8Button, 0);
        case 9:
            this->Root->SetRow(this->Num9Button, 2);
            this->Root->SetColumn(this->Num9Button, 0);
        default:
            break;
        }
    }
    else if (Loc == 2)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 2);
            this->Root->SetColumn(this->Num0Button, 1);
        case 1:
            this->Root->SetRow(this->Num1Button, 2);
            this->Root->SetColumn(this->Num1Button, 1);
        case 2:
            this->Root->SetRow(this->Num2Button, 2);
            this->Root->SetColumn(this->Num2Button, 1);
        case 3:
            this->Root->SetRow(this->Num3Button, 2);
            this->Root->SetColumn(this->Num3Button, 1);
        case 4:
            this->Root->SetRow(this->Num4Button, 2);
            this->Root->SetColumn(this->Num4Button, 1);
        case 5:
            this->Root->SetRow(this->Num5Button, 2);
            this->Root->SetColumn(this->Num5Button, 1);
        case 6:
            this->Root->SetRow(this->Num6Button, 2);
            this->Root->SetColumn(this->Num6Button, 1);
        case 7:
            this->Root->SetRow(this->Num7Button, 2);
            this->Root->SetColumn(this->Num7Button, 1);
        case 8:
            this->Root->SetRow(this->Num8Button, 2);
            this->Root->SetColumn(this->Num8Button, 1);
        case 9:
            this->Root->SetRow(this->Num9Button, 2);
            this->Root->SetColumn(this->Num9Button, 1);
        default:
            break;
        }
    }
    else if (Loc == 3)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 2);
            this->Root->SetColumn(this->Num0Button, 2);
        case 1:
            this->Root->SetRow(this->Num1Button, 2);
            this->Root->SetColumn(this->Num1Button, 2);
        case 2:
            this->Root->SetRow(this->Num2Button, 2);
            this->Root->SetColumn(this->Num2Button, 2);
        case 3:
            this->Root->SetRow(this->Num3Button, 2);
            this->Root->SetColumn(this->Num3Button, 2);
        case 4:
            this->Root->SetRow(this->Num4Button, 2);
            this->Root->SetColumn(this->Num4Button, 2);
        case 5:
            this->Root->SetRow(this->Num5Button, 2);
            this->Root->SetColumn(this->Num5Button, 2);
        case 6:
            this->Root->SetRow(this->Num6Button, 2);
            this->Root->SetColumn(this->Num6Button, 2);
        case 7:
            this->Root->SetRow(this->Num7Button, 2);
            this->Root->SetColumn(this->Num7Button, 2);
        case 8:
            this->Root->SetRow(this->Num8Button, 2);
            this->Root->SetColumn(this->Num8Button, 2);
        case 9:
            this->Root->SetRow(this->Num9Button, 2);
            this->Root->SetColumn(this->Num9Button, 2);
        default:
            break;
        }
    }
    else if (Loc == 4)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 1);
            this->Root->SetColumn(this->Num0Button, 0);
        case 1:
            this->Root->SetRow(this->Num1Button, 1);
            this->Root->SetColumn(this->Num1Button, 0);
        case 2:
            this->Root->SetRow(this->Num2Button, 1);
            this->Root->SetColumn(this->Num2Button, 0);
        case 3:
            this->Root->SetRow(this->Num3Button, 1);
            this->Root->SetColumn(this->Num3Button, 0);
        case 4:
            this->Root->SetRow(this->Num4Button, 1);
            this->Root->SetColumn(this->Num4Button, 0);
        case 5:
            this->Root->SetRow(this->Num5Button, 1);
            this->Root->SetColumn(this->Num5Button, 0);
        case 6:
            this->Root->SetRow(this->Num6Button, 1);
            this->Root->SetColumn(this->Num6Button, 0);
        case 7:
            this->Root->SetRow(this->Num7Button, 1);
            this->Root->SetColumn(this->Num7Button, 0);
        case 8:
            this->Root->SetRow(this->Num8Button, 1);
            this->Root->SetColumn(this->Num8Button, 0);
        case 9:
            this->Root->SetRow(this->Num9Button, 1);
            this->Root->SetColumn(this->Num9Button, 0);
        default:
            break;
        }
    }
    else if (Loc == 5)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 1);
            this->Root->SetColumn(this->Num0Button, 1);
        case 1:
            this->Root->SetRow(this->Num1Button, 1);
            this->Root->SetColumn(this->Num1Button, 1);
        case 2:
            this->Root->SetRow(this->Num2Button, 1);
            this->Root->SetColumn(this->Num2Button, 1);
        case 3:
            this->Root->SetRow(this->Num3Button, 1);
            this->Root->SetColumn(this->Num3Button, 1);
        case 4:
            this->Root->SetRow(this->Num4Button, 1);
            this->Root->SetColumn(this->Num4Button, 1);
        case 5:
            this->Root->SetRow(this->Num5Button, 1);
            this->Root->SetColumn(this->Num5Button, 1);
        case 6:
            this->Root->SetRow(this->Num6Button, 1);
            this->Root->SetColumn(this->Num6Button, 1);
        case 7:
            this->Root->SetRow(this->Num7Button, 1);
            this->Root->SetColumn(this->Num7Button, 1);
        case 8:
            this->Root->SetRow(this->Num8Button, 1);
            this->Root->SetColumn(this->Num8Button, 1);
        case 9:
            this->Root->SetRow(this->Num9Button, 1);
            this->Root->SetColumn(this->Num9Button, 1);
        default:
            break;
        }
    }
    else if (Loc == 6)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 1);
            this->Root->SetColumn(this->Num0Button, 2);
        case 1:
            this->Root->SetRow(this->Num1Button, 1);
            this->Root->SetColumn(this->Num1Button, 2);
        case 2:
            this->Root->SetRow(this->Num2Button, 1);
            this->Root->SetColumn(this->Num2Button, 2);
        case 3:
            this->Root->SetRow(this->Num3Button, 1);
            this->Root->SetColumn(this->Num3Button, 2);
        case 4:
            this->Root->SetRow(this->Num4Button, 1);
            this->Root->SetColumn(this->Num4Button, 2);
        case 5:
            this->Root->SetRow(this->Num5Button, 1);
            this->Root->SetColumn(this->Num5Button, 2);
        case 6:
            this->Root->SetRow(this->Num6Button, 1);
            this->Root->SetColumn(this->Num6Button, 2);
        case 7:
            this->Root->SetRow(this->Num7Button, 1);
            this->Root->SetColumn(this->Num7Button, 2);
        case 8:
            this->Root->SetRow(this->Num8Button, 1);
            this->Root->SetColumn(this->Num8Button, 2);
        case 9:
            this->Root->SetRow(this->Num9Button, 1);
            this->Root->SetColumn(this->Num9Button, 2);
        default:
            break;
        }
    }
    else if (Loc == 7)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 0);
            this->Root->SetColumn(this->Num0Button, 0);
        case 1:
            this->Root->SetRow(this->Num1Button, 0);
            this->Root->SetColumn(this->Num1Button, 0);
        case 2:
            this->Root->SetRow(this->Num2Button, 0);
            this->Root->SetColumn(this->Num2Button, 0);
        case 3:
            this->Root->SetRow(this->Num3Button, 0);
            this->Root->SetColumn(this->Num3Button, 0);
        case 4:
            this->Root->SetRow(this->Num4Button, 0);
            this->Root->SetColumn(this->Num4Button, 0);
        case 5:
            this->Root->SetRow(this->Num5Button, 0);
            this->Root->SetColumn(this->Num5Button, 0);
        case 6:
            this->Root->SetRow(this->Num6Button, 0);
            this->Root->SetColumn(this->Num6Button, 0);
        case 7:
            this->Root->SetRow(this->Num7Button, 0);
            this->Root->SetColumn(this->Num7Button, 0);
        case 8:
            this->Root->SetRow(this->Num8Button, 0);
            this->Root->SetColumn(this->Num8Button, 0);
        case 9:
            this->Root->SetRow(this->Num9Button, 0);
            this->Root->SetColumn(this->Num9Button, 0);
        default:
            break;
        }
    }
    else if (Loc == 8)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 0);
            this->Root->SetColumn(this->Num0Button, 1);
        case 1:
            this->Root->SetRow(this->Num1Button, 0);
            this->Root->SetColumn(this->Num1Button, 1);
        case 2:
            this->Root->SetRow(this->Num2Button, 0);
            this->Root->SetColumn(this->Num2Button, 1);
        case 3:
            this->Root->SetRow(this->Num3Button, 0);
            this->Root->SetColumn(this->Num3Button, 1);
        case 4:
            this->Root->SetRow(this->Num4Button, 0);
            this->Root->SetColumn(this->Num4Button, 1);
        case 5:
            this->Root->SetRow(this->Num5Button, 0);
            this->Root->SetColumn(this->Num5Button, 1);
        case 6:
            this->Root->SetRow(this->Num6Button, 0);
            this->Root->SetColumn(this->Num6Button, 1);
        case 7:
            this->Root->SetRow(this->Num7Button, 0);
            this->Root->SetColumn(this->Num7Button, 1);
        case 8:
            this->Root->SetRow(this->Num8Button, 0);
            this->Root->SetColumn(this->Num8Button, 1);
        case 9:
            this->Root->SetRow(this->Num9Button, 0);
            this->Root->SetColumn(this->Num9Button, 1);
        default:
            break;
        }
    }
    else if (Loc == 9)
    {
        switch (target)
        {
        case 0:
            this->Root->SetRow(this->Num0Button, 0);
            this->Root->SetColumn(this->Num0Button, 2);
        case 1:
            this->Root->SetRow(this->Num1Button, 0);
            this->Root->SetColumn(this->Num1Button, 2);
        case 2:
            this->Root->SetRow(this->Num2Button, 0);
            this->Root->SetColumn(this->Num2Button, 2);
        case 3:
            this->Root->SetRow(this->Num3Button, 0);
            this->Root->SetColumn(this->Num3Button, 2);
        case 4:
            this->Root->SetRow(this->Num4Button, 0);
            this->Root->SetColumn(this->Num4Button, 2);
        case 5:
            this->Root->SetRow(this->Num5Button, 0);
            this->Root->SetColumn(this->Num5Button, 2);
        case 6:
            this->Root->SetRow(this->Num6Button, 0);
            this->Root->SetColumn(this->Num6Button, 2);
        case 7:
            this->Root->SetRow(this->Num7Button, 0);
            this->Root->SetColumn(this->Num7Button, 2);
        case 8:
            this->Root->SetRow(this->Num8Button, 0);
            this->Root->SetColumn(this->Num8Button, 2);
        case 9:
            this->Root->SetRow(this->Num9Button, 0);
            this->Root->SetColumn(this->Num9Button, 2);
        default:
            break;
        }
    }
}


NumberPad::NumberPad()
    : m_isErrorVisualState(false)
{
    InitializeComponent();

    const auto& localizationSettings = LocalizationSettings::GetInstance();

    this->DecimalSeparatorButton->Content = localizationSettings.GetDecimalSeparator();
    this->Num0Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('0');
    this->Num1Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('1');
    this->Num2Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('2');
    this->Num3Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('3');
    this->Num4Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('4');
    this->Num5Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('5');
    this->Num6Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('6');
    this->Num7Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('7');
    this->Num8Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('8');
    this->Num9Button->Content = localizationSettings.GetDigitSymbolFromEnUsDigit('9');
    int myLoc;
    for (int i = 0; i < 10; i++)
        visit[i] = false;

    for (int i = 0; i < 10; i++)
    {
        while (1)
        {
            myLoc = getRandomNumber(0, 9);
            if (!visit[myLoc])
                break;
        }
        visit[myLoc] = true;
        SetTheButton(i, myLoc);
    }

    /*for (int i = 0; i < 10; i++) {
        if (ranNum[i] == 7)
            continue;
        SetTheButton(i, ranNum[i]);
    }*/
}


void NumberPad::OnCurrentRadixTypePropertyChanged(NumberBase /* oldValue */, NumberBase newValue)
{
    Num0Button->IsEnabled = true;
    Num1Button->IsEnabled = true;
    Num2Button->IsEnabled = true;
    Num3Button->IsEnabled = true;
    Num4Button->IsEnabled = true;
    Num5Button->IsEnabled = true;
    Num6Button->IsEnabled = true;
    Num7Button->IsEnabled = true;
    Num8Button->IsEnabled = true;
    Num9Button->IsEnabled = true;

    if (newValue == NumberBase::BinBase)
    {
        Num2Button->IsEnabled = false;
        Num3Button->IsEnabled = false;
        Num4Button->IsEnabled = false;
        Num5Button->IsEnabled = false;
        Num6Button->IsEnabled = false;
        Num7Button->IsEnabled = false;
        Num8Button->IsEnabled = false;
        Num9Button->IsEnabled = false;
    }
    else if (newValue == NumberBase::OctBase)
    {
        Num8Button->IsEnabled = false;
        Num9Button->IsEnabled = false;
    }
}

bool NumberPad::IsErrorVisualState::get()
{
    return m_isErrorVisualState;
}

void NumberPad::IsErrorVisualState::set(bool value)
{
    if (m_isErrorVisualState != value)
    {
        m_isErrorVisualState = value;
        String ^ newState = m_isErrorVisualState ? L"ErrorLayout" : L"NoErrorLayout";
        VisualStateManager::GoToState(this, newState, false);
    }
}
