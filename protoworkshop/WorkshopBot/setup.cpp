

/*
 * setup.cpp -- part of the WorkshopBot project.
 * Setup of SerialUI and menu system
 * Nitin Vinayak Agrawal
 * Robocon 
 * 
 * Copyright (C) 2017 Nitin Vinayak Agrawal
 * 
 * Generated by DruidBuilder [https://devicedruid.com/], 
 * as part of project "4627378837c8449eaff9a98bd9bcae72tGPsyZXBln",
 * aka WorkshopBot.
 * 
 * Druid4Arduino, Device Druid, Druid Builder, the builder 
 * code brewery and its wizards, SerialUI and supporting 
 * libraries, as well as the generated parts of this program 
 * are 
 *            Copyright (C) 2013-2017 Pat Deegan 
 * [http://psychogenic.com/ | http://flyingcarsandstuff.com/]
 * and distributed under the terms of their respective licenses.
 * See http://devicedruid.com for details.
 * 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE 
 * PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, 
 * YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR
 * CORRECTION.
 * 
 * Keep in mind that there is no warranty and you are solely 
 * responsible for the use of all these cool tools.
 * 
 * Play safe, have fun.
 * 
 */


/* we need the SerialUI lib */
#include <SerialUI.h>
#include "WorkshopBotSettings.h"

/* our project specific types and functions are here */
#include "WorkshopBot.h"



/* MySUI
 * Our SerialUI Instance, through which we can send/receive
 * data from users. Actually instantiated here, for global use.
 */
SUI::SerialUI MySUI(3);


/*
 * The container for MyInputs, which
 * holds all the variables for the various inputs.
 * Actually instantiated here, for global use.
 */
MyInputsContainerSt MyInputs;


/* MyTracked
 * A structure to hold the tracked variables, which will 
 * automatically update the druid UI when modified by this 
 * program.
 * Actually instantiated here, for global use.
 */
MyTrackedVarsContainerSt MyTracked;






bool SetupSerialUI() {

	MySUI.setGreeting(F(serial_ui_greeting_str));
	// SerialUI acts just like (is actually a facade for)
	// Serial.  Use _it_, rather than Serial, throughout the
	// program.
	// basic setup of SerialUI:
	MySUI.begin(serial_baud_rate); // serial line open/setup
	MySUI.setTimeout(serial_readtimeout_ms);   // timeout for reads (in ms), same as for Serial.
	MySUI.setMaxIdleMs(serial_maxidle_ms);    // timeout for user (in ms)
	// how we are marking the "end-of-line" (\n, by default):
	MySUI.setReadTerminator(serial_input_terminator);
	// project UID -- will be used to remember state in Druid...
	MySUI.setUID(SUI_STR("4627378837c8449eaff9a98bd9bcae72tGPsyZXBln"));

	
	
	
	// Add variable state tracking 
	
	MySUI.trackState(
		SUI_STR("Distance"),
		&(MyTracked.Distance));
	
	
	
	// a few error messages we hopefully won't need
	
	SUI_FLASHSTRING CouldntAddItemErr = F("Could not add item?");
	
	// get top level menu, to start adding items
	SUI::Menu * topMenu = MySUI.topLevelMenu();
	if (! topMenu ) {
		// well, that can't be good...
		MySUI.returnError(F("Very badness in sEriALui!1"));
		return false;
	}
	
	
	
	/* *** Main Menu *** */

	
	if( ! topMenu->addRequest(
		&(MyInputs.Forward),
		SUI_STR("Forward"),
		NULL,
		-255,
		255,
		MainMenu::ForwardChanged)) {
		MySUI.returnError(CouldntAddItemErr);
		return false;
	}
	
	if( ! topMenu->addRequest(
		&(MyInputs.Turn),
		SUI_STR("Turn"),
		NULL,
		-255,
		255,
		MainMenu::TurnChanged)) {
		MySUI.returnError(CouldntAddItemErr);
		return false;
	}
	
	if( ! topMenu->addRequest(
		&(MyInputs.ServoDir),
		SUI_STR("ServoDir"),
		NULL,
		-90,
		90,
		MainMenu::ServoDirChanged)) {
		MySUI.returnError(CouldntAddItemErr);
		return false;
	}

	
	
	
	return true;
	
}


