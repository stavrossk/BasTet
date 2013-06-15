

/*
    Bastet - tetris clone with embedded bastard block chooser
    (c) 2005-2009 Federico Poloni <f.polonithirtyseven@sns.it> minus 37

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */




#include "Ui.hpp"
#include "Config.hpp"
#include "BastetBlockChooser.hpp"
#include <boost/assign.hpp>

#include <windows.h>

//DBG
#include <iostream>
#include <boost/format.hpp>


using namespace Bastet;
using namespace std;
using namespace boost;
using namespace boost::assign;




// Raphael R. - Console Window Fixes
void WindowsConsoleWindowCheat(void);


BOOL ConsoleControlHandler(DWORD);





int main(int argc, char **argv)
{



	// Raphael R. - Making the "X"-Button don't crash the app. Ironic, isn't it?
	WindowsConsoleWindowCheat();
  
  
	Ui ui;
  
	
	while(1)
	{
    
		int choice=ui.MenuDialog
			(
			
				list_of
					("Play! (normal version)")
					("Play! (harder version)")
					("View highscores")
					("Customize keys")
					("Quit")
				
			);
    
		
		switch(choice)
		{

			case 0:
			{

				//ui.ChooseLevel();
      
				BastetBlockChooser bc;
      
				ui.Play(&bc);
      
				ui.HandleHighScores(difficulty_normal);
      
				ui.ShowHighScores(difficulty_normal);
    
			}


			break;
    
			
			case 1:
			{

				//ui.ChooseLevel();
      
				NoPreviewBlockChooser bc;
      
				ui.Play(&bc);
      
				ui.HandleHighScores(difficulty_hard);
      
				ui.ShowHighScores(difficulty_hard);
    
			}


			break;
    
			
			case 2:
				ui.ShowHighScores(difficulty_normal);
				ui.ShowHighScores(difficulty_hard);
      
			break;
    
			case 3:
				ui.CustomizeKeys();
      
			break;

			case 4:
				exit(0);
			break;

    
		}



	}



}








void WindowsConsoleWindowCheat(void)
{

	SetConsoleCtrlHandler
		(

			(PHANDLER_ROUTINE) ConsoleControlHandler, TRUE
		
		);

}





BOOL ConsoleControlHandler(DWORD dwType)
{


	if(dwType == CTRL_CLOSE_EVENT)
	{

		exit(0);
	
	}
	
	return FALSE; // Muahahahaha



}






