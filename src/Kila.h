/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>
#include "IdealReactors.h"
#include "canteraInterface.h"

namespace ASALI
{
    class Kila : public Gtk::Window
    {
        public:
            Kila(Cantera::ThermoPhase* thermo,
                 Cantera::Transport*   transport);
            
            virtual ~Kila();
            
            #include "UnitConversion.H"
            
        private:

            void exit();
            void discrimer();
            void inputReader();
            void showAtomNames();
            void transportMenu();
            void thermoMenu();
            void allMenu();
            void equilibriumMenu();
            void reactorsMenu1();
            void reactorsMenu2();
            void transportResults();
            void thermoResults();
            void allResults();
            void equilibriumResults();
            void equilibriumRun();
            void transportSave();
            void thermoSave();
            void allSave();
            void reactorSave();
            void equilibriumSave();
            void cpUnitConversion(bool check);
            void sUnitConversion(bool check);
            void hUnitConversion(bool check);
            void condUnitConversion(bool check);
            void diffUnitConversion(bool check);
            void diffSpecies(unsigned int row);
            void initialFractionUnitConversion();
            void finalFractionUnitConversion();
            void muUnitConversion(bool check);
            void backToMenu();
            void savedMessage();
            void vacuumEvaluation();
            void runReactors();
            void equations();
            void changeCursor();
            void saveKineticInput();
            void loadKineticInput();
            bool menu(GdkEventButton*);

            
            std::vector<bool> setReactors();
           

            Gtk::Button       doneThermoButton_;
            Gtk::Button       doneTransportButton_;
            Gtk::Button       doneAllButton_;
            Gtk::Button       doneReactorsButton_;
            Gtk::Button       discrimerButton_;
            Gtk::Button       transportButton_;
            Gtk::Button       thermoButton_;
            Gtk::Button       allButton_;
            Gtk::Button       equilibriumButton_;
            Gtk::Button       reactorsButton_;
            Gtk::Button       transportSaveButton_;
            Gtk::Button       thermoSaveButton_;
            Gtk::Button       allSaveButton_;
            Gtk::Button       reactorSaveButton_;
            Gtk::Button       equilibriumSaveButton_;
            Gtk::Button       calculateButton_;
            Gtk::Button       equationsButton_;
            Gtk::Button       runButton_;
            Gtk::Button       startButton_;
            Gtk::Button       loadKineticButton_;

            Gtk::Box          menuBox_;
            Gtk::Box          transportBox_;
            Gtk::Box          thermoBox_;
            Gtk::Box          allBox_;
            Gtk::Box          cpBox_;
            Gtk::Box          sBox_;
            Gtk::Box          hBox_;
            Gtk::Box          condBox_;
            Gtk::Box          muBox_;
            Gtk::Box          diffBox_;
            Gtk::Box          reactorsTimeBox_;
            Gtk::Box          EattBox_;
            Gtk::Box          kBox_;

            Gtk::ButtonBox    exitButtonBox_;
            Gtk::ButtonBox    discrimerButtonBox_;
            Gtk::ButtonBox    buttonsBox_;
            Gtk::ButtonBox    startButtonBox_;
            
            Gtk::EventBox     logoEventBox_;

            Gtk::Label        heading_;
            Gtk::Label        tempLabel_;
            Gtk::Label        pressLabel_;
            Gtk::Label        fractionLabel_;
            Gtk::Label        cpLabel_;
            Gtk::Label        hLabel_;
            Gtk::Label        sLabel_;
            Gtk::Label        condLabel_;
            Gtk::Label        muLabel_;
            Gtk::Label        diffLabel_;
            Gtk::Label        reactorsTypeLabel_;
            Gtk::Label        reactorsTimeLabel_;
            Gtk::Label        reactorsReactionLabel_;
            Gtk::Label        reactorsParametersLabel_;
            Gtk::Label        kLabel_;
            Gtk::Label        nLabel_;
            Gtk::Label        EattLabel_;
            Gtk::Label        aLabel_;
            Gtk::Label        bLabel_;
            Gtk::Label        initialStateLabel_;
            Gtk::Label        finalStateLabel_;

            Gtk::Grid         grid_;
            Gtk::Grid         inputGrid_;
            Gtk::Grid         thermoGrid_;
            Gtk::Grid         transportGrid_;
            Gtk::Grid         allGrid_;
            Gtk::Grid         reactorsGrid_;
            Gtk::Grid         reactorsDimensionGrid_;
            Gtk::Grid         reactorsParameterGridLabels_;
            Gtk::Grid         equilibriumGrid_;

            Gtk::Image        bigLogo_;
            Gtk::Image        smallLogo_;
            Gtk::Image        equationsImage_;
            Gtk::Image        reactionImage_;
            
            Gtk::Entry        tempEntry_;
            Gtk::Entry        pressEntry_;
            Gtk::Entry        reactorsTimeEntry_;

            Gtk::ComboBoxText tempCombo_;
            Gtk::ComboBoxText pressCombo_;
            Gtk::ComboBoxText fractionCombo_;
            Gtk::ComboBoxText thermoCombo_;
            Gtk::ComboBoxText transportCombo_;
            Gtk::ComboBoxText allCombo_;
            Gtk::ComboBoxText reactorsTypeCombo_;
            Gtk::ComboBoxText reactorsTimeCombo_;
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText sCombo_;
            Gtk::ComboBoxText hCombo_;
            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText diffCombo_;
            Gtk::ComboBoxText muCombo_;
            Gtk::ComboBoxText EattCombo_;
            Gtk::ComboBoxText kCombo_;
            Gtk::ComboBoxText equilibriumCombo_;
            Gtk::ComboBoxText initialFractionCombo_;
            Gtk::ComboBoxText finalFractionCombo_;
           

            std::vector<Gtk::Label *>          transportVector_;
            std::vector<Gtk::Label *>          thermoVector_;
            std::vector<Gtk::Label *>          allVector_;
            std::vector<Gtk::Label *>          cpVector_;
            std::vector<Gtk::Label *>          hVector_;
            std::vector<Gtk::Label *>          sVector_;
            std::vector<Gtk::Label *>          condVector_;
            std::vector<Gtk::Label *>          muVector_;
            std::vector<Gtk::Label *>          diffVector_;
            std::vector<Gtk::Label *>          reactionNumbers_;
            std::vector<Gtk::Label *>          empty_;
            std::vector<Gtk::Label *>          initialFractionVector_;
            std::vector<Gtk::Label *>          finalFractionVector_;
            std::vector<Gtk::Label *>          equilibriumVector_;
            std::vector<Gtk::ComboBoxText *>   speciesCombo_;
            std::vector<Gtk::Box *>            diffBoxVector_;
            std::vector<Gtk::Box *>            reactorsReactionBox_;
            std::vector<Gtk::Entry *>          nameEntry_;
            std::vector<Gtk::Entry *>          fractionEntry_;
            std::vector<Gtk::Entry *>          kEntry_;
            std::vector<Gtk::Entry *>          nEntry_;
            std::vector<Gtk::Entry *>          EattEntry_;
            std::vector<Gtk::Entry *>          aEntry_;
            std::vector<Gtk::Entry *>          bEntry_;
            std::vector<Gtk::Grid *>           reactorsParameterGrid_;
            std::vector<Gtk::Grid *>           reactorsButtonGrid_;
            std::vector<Gtk::Button *>         exitButton_;
            std::vector<Gtk::Button *>         backButton_;
            std::vector<Gtk::Button *>         nextButton_;

            std::vector<std::vector<Gtk::Entry *> >        reactionEntry_;
            std::vector<std::vector<Gtk::ComboBoxText *> > stoichCombo_;
            std::vector<std::vector<Gtk::Label *> >        reactionLabel_;

            double         T_;
            double         Teq_;
            double         p_;
            double         d_;
            double         Kn_;
            double         diffK_;
            double         tau_;
            double         specieConverter_;

            std::pair<unsigned int,bool>       checkInput_;

            std::vector<double>      cp_;
            std::vector<double>      h_;
            std::vector<double>      s_;
            std::vector<double>      x_;
            std::vector<double>      y_;
            std::vector<double>      xeq_;
            std::vector<double>      yeq_;
            std::vector<double>      MW_;
            std::vector<double>      cond_;
            std::vector<double>      mu_;
            std::vector<double>      kr_;
            std::vector<double>      Eattr_;
            std::vector<double>      nr_;
            std::vector<double>      ar_;
            std::vector<double>      br_;
            
            std::vector<unsigned int>      index1_;
            std::vector<unsigned int>      index2_;

            std::vector<std::vector<int> > stoich_;

            std::vector<std::vector<double> > diff_;
            
            std::vector<std::string> n_;
            
            std::string window_;
            
            int            OP_;
            unsigned int   NS_;
            unsigned int   NR_;
           
            ASALI::IdealReactors        *reactors_;

            Cantera::ThermoPhase        *thermo_;
            Cantera::Transport          *transport_;
            ASALI::canteraInterface     *canteraInterface_;

            unsigned int specieIndex(const std::string n, const std::vector<std::string> v);
            bool         reactionInputCheck(bool test);
            void         checkInput(unsigned int i);
            
            void         cleanThermo();
            void         cleanTransport();
            void         cleanAll();
            
            

    };
}
