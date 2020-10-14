#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intro()
{
	printf("\n\n\n================================================================================\n");
	printf("\t\t\tWelcome to Caro-on-a-PC v1.0");
	printf("\n\t    Choose the corresponding number for its operation:");
	printf("\n\t\t1. PLAY\n\t\t2. CHANGE PLAYER\n\t\t3. QUIT");
	printf("\n\t--> Selection: ");
}

void play()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t    ---> Loading game. Please wait...<---");
	printf("\n\t\t    ---> <Simulating gameplay here>  <---");
	printf("\n\n\n\n\n\n\n\n\n");
}

void cMenu()
{
	printf("\n\n\n\n\n\n\n\n    [Changing Players] Please choose an operation:\n");
	printf("\n\t\t1. View/Set active profiles\n\t\t2. Add profiles (Note: Maximum of 4 profiles)\n\t\t3. Remove profiles\n\t\t4. Main menu");
	printf("\n\t--> Selection: ");
}

struct player
{
	char nick[32];
	bool free = true; 
	bool active = false;
};

void setTrue()
{
	this.true = false;
}

extern viewEx(int x, char name[], bool sActive)
{
	printf("\nProfile ID-%d:\n\tNickname: %s",x+1,name);
	if (sActive == false) 
		printf("\n\tStatus: Ready\n");
	else
		printf("\n\tStatus: Active\n");
}

extern view(int x, char name[], bool sActive)
{
	printf("\nProfile ID-%d:\n\tNickname: %s",x+1,name);
	if (sActive == false) 
		printf("\n\tStatus: Ready\n");
	else
		printf("\n\tStatus: Active\n");
}

main()
{
	char pnick[32];
	bool exitGame, i_valid, addPlayer, c_valid, maxPlayer, opDeny, delPlayer, exitDel, confirm, viewSetPlayer, doContinue, setValid, setPass;
	int i_sel, c_sel, d_sel, vs_sel, sa1, sa2, cDel, i, cc, vs_con, na = 0;
	char c[1];
	struct player p[4];
					
	while (exitGame == false)
	{
		i_valid = c_valid = false;
		intro();
		while (i_valid == false)
		{
			scanf("%d",&i_sel);
		
			switch (i_sel)
			{
				case 1:
					play();
					exitGame = true;
					i_valid = true;
					break;
				case 2:
					i_valid = true;
					exitGame = false;
					break;
				case 3:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t   ---> You have exited the application <---\n\n\n\n\n\n\n\n\n");
					exitGame = true;
					i_valid = true;
					break;
				default:
					printf("Unknown operation. Please try again: ");
					i_valid = false;
					break;
			}
			if (i_valid == true) break;
		}
		if (exitGame == true) break;
		
		cMenu();
		
		while (c_valid == false)
		{
			viewSetPlayer = delPlayer = addPlayer = false;
			scanf("%d",&c_sel);
			addPlayer = delPlayer = false;
			switch (c_sel)
			{
				case 1: //   VIEW AND SET ACTIVE players function
					viewSetPlayer = true;
					break;
				case 2:	//	 ADD player function
					addPlayer = true;
					break;
				case 3: //	 REMOVE players function
					delPlayer = true;
					break;
				case 4:	//	 BACK TO MAIN MENU function
					c_valid = true;
					exitGame = false;
					break;
				default:
					printf("Unknown operation. Please try again: ");
					c_valid = false;
					break;
			}
			if (c_valid == true) break;
			
			if (addPlayer == true)
			{
				maxPlayer = false;
				for (i = 0; i <= 4; i++)
				{
					if (p[i].free == false) na++;
				}
				
				if (na == 5)
				{
					maxPlayer = true;
					na = 0;
				}
				
				if (maxPlayer == false )
				{
					for (i = 0; i < 4; i++)
					{
						if (p[i].free == true)
						{
							printf("\n\n\n\n\n[INFO] An empty profile is found.\n[INFO] Enter your nickname, this will be visible to other players: ");
							scanf("%s",&pnick);
							strcpy(p[i].nick,pnick);
							p[i].free = false;
							printf("\n\n[SUCCESS] Player profile successfully added.\n\t--> Choose another operation: ");
							na = 0;
							break;
						}
					}
				}
				else
				{
					printf("\n\n\n\n\n[FAILED] No empty profile can be found. Please remove an existing profile first.");
					printf("\n\t--> Choose another operation: ");
					na = 0;
				}
			}
			
			if (delPlayer == true)
			{
				confirm = false;
				na = 0;
				printf("\n\n[INFO] Accessing player's profiles... Please wait\n\n");
				for (i = 0; i < 4; i++)
				{
					if (p[i].free == true) na++;
				}
				
				if (na == 4) 
				{
					printf("\n[FAILED] There is no existing profiles. Maybe create some?\n\t--> Choose another operation: ");
					na = 0;
				}
				else
				{
					printf("[INFO] Here are the existing profiles:\n");
					for (i = 0; i < 4; i++)
					{
						if (p[i].free == false) viewEx( i, p[i].nick, p[i].active );
					}
					printf("\n\n[INFO] Which profile should be removed? Please choose the corresponding ID\n   -Enter 5 to cancel.\n\n\t--> Selection: ");
					while (exitDel == false)
					{
						scanf("%d",&cc);
						if (cc > 4)
						{
							printf("\n\n[ERROR] You cancelled the operation.\n\n\t--> Choose another operation: ");
							exitDel = true;
							break;
						}
						else
						{
							if (p[cc-1].free == false)
							{
								printf("\n\n[WARNING] You are about the delete %s's profile. \n    Proceed? (1 for YES and 0 for NO)\n\n\t--> Answer: ",p[cc-1].nick);
								scanf("%d",&cDel);
			
								if (cDel == 1 && confirm == false)
								{
									printf("\n\n[SUCCESS] %s's profile has been successfully removed.\n\t--> Choose another operation: ",p[cc-1].nick);
									memset(p[cc-1].nick,0,strlen(p[cc-1].nick));
									p[cc-1].free = true;
									p[cc-1].active = false;
									exitDel = true;
									confirm = true;
									break;
								}
								if (cDel == 0 && confirm == false) 
								{
									confirm = true;
									exitDel = true;
									printf("[FAILED] You cancelled the action.\n\t--> Choose another operation: ");
									break;
								}
							}
							else
							{
								printf("\n[ERROR] Failed to find the desired profile.\n\t--> Choose another operation: ");
								exitDel = true;
								break;
							}
						}
					}
				}
				na = 0;
			}
			
			if (viewSetPlayer == true)
			{
				setValid = doContinue = false;
				na = 0;
				for (i = 0; i < 4; i++)
				{
					if (p[i].free == true) na++;
				}
				
				if (na == 4)
				{
					printf("\n[FAILED] There is no existing profiles. Maybe create some?\n\n\t--> Choose another operation: ");
					na = 0;
				}
				else
				{
					printf("\n\n[INFO] Here are the created profiles:\n");
					for (i = 0; i < 4; i++) 
					{
						if (p[i].free == false) view(i, p[i].nick, p[i].active);
						p[i].active = false;
					}
					
					while (doContinue == false)
					{
						printf("\n\n[INFO] What to do now?\n\t1. Set active profile for game\n\t2. Set passive profile\n\t3. Choose another operation\n\n\t--> Selection: ");
						scanf("%d",&vs_sel); 
						
						switch (vs_sel)
						{
							case 1:
								na = 0;
								for (i = 0; i < 4; i++) if (p[i].free == true) na++;
								if (na >= 3)
								{
									printf("\n\n[FAILED] Not enough players to set active. Maybe create some?\n\n\t--> Choose another operation: ");
									doContinue = true;
									break;
								}
								printf("\n\n[INFO] Enter 2 profiles ID to set to Active for game (each must be spaced): ");
								
								while (setValid == false)
								{
									scanf("%d %d",&sa1,&sa2);
									if (sa1 >= 0 && sa1 <= 4 && sa2 >= 0 && sa2 <= 4 && sa1 != sa2)
									{
										p[sa1-1].active = true;
										p[sa2-1].active = true;
										printf("\n[SUCCESS] Status of profile name '%s' and '%s' have been set to ACTIVE.\n\n\t--> Choose another operation: ",p[sa1-1].nick,p[sa2-1].nick);
										setValid = true;
										doContinue = true;
										break;
									}
									
									if (sa1 == sa2)
									{
										printf("\n[INFO] This means that you only set 1 profile to be active. \n    Proceed? (1 for YES and 0 for NO)\n\n\t--> Answer: ");
										scanf("%d",&vs_con);
										
										if (vs_con == 1)
										{
											p[sa1-1].active = true;
											printf("\n[SUCCESS] Status of profile name %s has been set to ACTIVE.\n\n\t--> Choose another operation: ",p[sa1-1].nick);
											setValid = true;
											doContinue = true;
										}
										
										else
										{
											printf("[INFO] You skipped the operation.\n\n\t--> Enter 2 IDs again: ");
											doContinue = false;
											setValid = false;
										}
									}
									if (setValid == true) break;
								}
								break;
							case 2:
								setPass = false;
								na = 0;
								for (i = 0; i < 4; i++) if (p[i].active == false) na++;
								if (na == 0)
								{
									printf("\n\n[ERROR] There is no active players. Set profiles for game? \n    Proceed? (1 for YES and 0 for NO)\n\n\t--> Answer: ");
									scanf("%d",&vs_con);
									
									if (vs_con == 0)
									{
										printf("\n[INFO] You skipped the operation.\n\n\t--> Choose another operation: ");
										doContinue = true;
										break;
									}
									else
									{
										doContinue = false;
										break;
									}
								}
								else
								{
									printf("\n\n[INFO] Enter an ID of profile to set status to PASSIVE: ");
									
									while (setPass == false)
									{
										scanf("%d",&vs_sel); 
										
										if (vs_sel < 0 && vs_sel > 4)
										{
											printf("\n\n[ERROR]: Invalid choice. Please try again: ");
											doContinue = false;
										}
										else if (vs_sel > 0 && vs_sel <= 4)
										{
											p[vs_sel-1].active = false;
											printf("\n\n[SUCCESS] Status of profile name '%s' has been set to PASSIVE.\n\n\t--> Choose another operation: ",p[vs_sel-1].nick);
											doContinue = true;
											setValid = true;
											setPass = true;
										}
										if (setPass == true) break;
									}
								}
								break;
							case 3:
								printf("\n\n[INFO] You have chosen for another operation. Choose it now: ");
								doContinue = true;
								break;
						}
						if (doContinue == true) break;
					}
				}
			}
			na = 0;
		}
		printf("\n\n\n\n\n\n\n");
	}
}
