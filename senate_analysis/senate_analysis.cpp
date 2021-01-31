#include <iostream>
#include <string>
#include <fstream>


void Entering_dem();
void Entering_gop();
void Entering_inde();
void Printing_menu();
void Upload_menu();
void Analysis_menu();
void automatic_loading();
bool  Scaning_names(bool red_flag, std::string first_name_2, std::string last_name_2);


struct Senator
{
    std::string first_name;
    std::string last_name;

    std::string party;
    std::string state;

};


std::ofstream data_file("list.txt", std::ios::app);
std::ifstream in_coming("list.txt");



Senator democrat_list[100];
Senator republican_list[100];
Senator independent_list[10];

int total_names = 0;

int main()
{
    int x = 1;
    int selection;


    automatic_loading();


    do
    {
        std::string name1;
        std::string name2;
        std::cout << std::endl;
        std::cout << "[Select political party]" << std::endl;

        std::cout << "1) Democrats " << std::endl;
        std::cout << "2) Republicans " << std::endl;
        std::cout << "3) Independent " << std::endl;
        std::cout << "4) Show all Senators " << std::endl;
        std::cout << "5) delete List " << std::endl;
        std::cout << "6) Upload menu " << std::endl;
        std::cout << "7) analysis " << std::endl;
        std::cout << "8) Close program " << std::endl;
        std::cin >> selection;

        system("cls");

        if (selection == 1)
        {
            Entering_dem();
        }
        else if (selection == 2)
        {
            Entering_gop();
        }
        else if (selection == 3)
        {
            Entering_inde();
        }
        else if (selection == 4)
        {
            Printing_menu();
        }
        else if (selection == 5)
        {


            std::cout << "This option is not ready yet!" << std::endl;
        }
        else if (selection == 6)
        {
            Upload_menu();
        }
        else if (selection == 7)
        {
            Analysis_menu();
        }
        else if (selection == 8)
        {
            x = 0;
        }
        else
        {
            std::cout << "Invalid selection! Please try again. " << std::endl;
        }

    } while (x);





    return 0;
}




void Entering_dem()
{

    std::string party_2;
    std::string first_name_2;
    std::string last_name_2;
    std::string state_2;

    bool red_flag = false;

    std::cout << "[Entering Democrat Sentor]" << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        
        if (democrat_list[i].first_name == "")
        {
            party_2 = "Democrat";

            std::cout << "Enter Senator's first name: " << std::endl;
            std::cin >> first_name_2;

            std::cout << "Enter Senator's last name: " << std::endl;
            std::cin >> last_name_2;


            //scaning names to see if already in data base
            if (Scaning_names(red_flag, first_name_2, last_name_2) == true)
            {
                break;
            }

            std::cout << "Enter Sentor's state: " << std::endl;
            std::cin >> state_2;

            data_file << party_2 << std::endl << first_name_2 << std::endl << last_name_2
                << std::endl << state_2 << std::endl;
            std::cout << "You have successfully entered a Democartic Senator! " << std::endl;
            break;
        }
    }
}


void  Entering_gop()
{

    std::string party_2;
    std::string first_name_2;
    std::string last_name_2;
    std::string state_2;

    bool red_flag = false;

    std::cout << "[Entering Republican Sentor] " << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {
        
        if (republican_list[i].first_name == "")
        {
            party_2 = "Republican";
            republican_list[i].party = "Republican";
            std::cout << "Enter Senator's first name: " << std::endl;
            std::cin >> first_name_2;

            std::cout << "Enter Senator's last name: " << std::endl;
            std::cin >> last_name_2;


            //scaning names to see if already in data base
            if (Scaning_names(red_flag, first_name_2, last_name_2) == true)
            {
                break;
            }

            std::cout << "Enter Sentor's state: " << std::endl;
            std::cin >> state_2;

            data_file << party_2 << std::endl << first_name_2 << std::endl
                << last_name_2 << std::endl << state_2 << std::endl;
            std::cout << "You have successfully entered a G.O.P Senator! " << std::endl;
            break;
        }
    }
}




void Entering_inde()
{
    std::string party_2;
    std::string first_name_2;
    std::string last_name_2;
    std::string state_2;
    bool red_flag = false;

    std::cout << "[Entering Independent Sentor] " << std::endl << std::endl;

    for (int i = 0; i < 100; i++)
    {


        if (independent_list[i].first_name == "")
        {
            party_2 = "Independent";
            independent_list[i].party = "Independent";
            std::cout << "Enter Senator's first name: " << std::endl;
            std::cin >> first_name_2;

            std::cout << "Enter Senator's last name: " << std::endl;
            std::cin >> last_name_2;


            //scaning names to see if already in data base
            if (Scaning_names(red_flag, first_name_2, last_name_2) == true)
            {
                break;
            }


            std::cout << "Enter Sentor's state: " << std::endl;
            std::cin >> state_2;

            data_file << party_2 << std::endl << first_name_2 << std::endl
                << last_name_2 << std::endl << state_2 << std::endl;
            break;
        }
    }


}









void Printing_menu()
{
    int counter_1 = 0;



    for (int i = 0; i < 100; i++)
    {

        if (democrat_list[i].first_name != "")
        {
            counter_1++;
            std::cout << counter_1 << " " << democrat_list[i].party << " " << democrat_list[i].first_name <<
                " " << democrat_list[i].last_name << ": State :" << democrat_list[i].state << std::endl;
        }
        else if (total_names == 0)
        {
            std::cout << "There are no names in data base. " << std::endl;
            break;
        }
        else
        {

        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (republican_list[i].first_name != "")
        {
            counter_1++;
            std::cout << counter_1 << " " << republican_list[i].party << " " << republican_list[i].first_name <<
                " " << republican_list[i].last_name << ": State :" << republican_list[i].state << std::endl;
        }
        else
        {

        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (independent_list[i].first_name != "")
        {
            counter_1++;
            std::cout << counter_1 << " " << independent_list[i].party << " " << independent_list[i].first_name <<
                " " << independent_list[i].last_name << ": State :" << independent_list[i].state << std::endl;
        }
        else
        {

        }
    }
   


}




void Upload_menu()
{

    int x = 1;
    int selection;
    int name_counter = 0;


    std::string party_1;
    std::string first_name_1;
    std::string last_name_1;
    std::string state_1;

    std::ofstream data_file("list.txt", std::ios::app);
    std::ifstream in_coming("list.txt");

    do
    {
        std::cout << "[Download Menu]" << std::endl;
        std::cout << "1)Upload ." << std::endl;
        std::cout << "2)Back to main menu ." << std::endl;
        std::cin >> selection;

        if (selection == 1)
        {
            while (in_coming >> party_1 >> first_name_1 >> last_name_1 >> state_1)
            {
                name_counter++;

                if (party_1 == "Democrat")
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (democrat_list[i].first_name == "")
                        {
                            democrat_list[i].party = party_1;
                            democrat_list[i].first_name = first_name_1;
                            democrat_list[i].last_name = last_name_1;
                            democrat_list[i].state = state_1;
                            break;
                        }
                        else
                        {
                            // skip
                        }
                    }
                }
                else if (party_1 == "Republican")
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (republican_list[i].first_name == "")
                        {
                            republican_list[i].party = party_1;
                            republican_list[i].first_name = first_name_1;
                            republican_list[i].last_name = last_name_1;
                            republican_list[i].state = state_1;
                            break;
                        }

                    }
                }
                else if (party_1 == "Independent")
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (independent_list[i].first_name == "")
                        {
                            independent_list[i].party = party_1;
                            independent_list[i].first_name = first_name_1;
                            independent_list[i].last_name = last_name_1;
                            independent_list[i].state = state_1;
                            break;
                        }

                    }
                }
             // end of while loop
            }
            system("cls");
            std::cout << name_counter << " Names have been downloaded." << std::endl;
            total_names = name_counter;
        }
        else if (selection == 2)
        {
            x = 0;
        }
        else
        {
            std::cout << "Invalid selection! Please try again. " << std::endl;
        }

        

    } while (x);

}





void Analysis_menu()
{
    int sentor_counter = 0;
    int dem_counter = 0;
    int repu_counter = 0;
    int inde_counter = 0;


    //counting dems
    for (int i = 0; i < 100; i++)
    {
        if (democrat_list[i].party != "")
        {
            dem_counter++;
        }
        else
        {
            // Doing nothing
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (republican_list[i].party != "")
        {
            repu_counter++;
        }
        else
        {
            // Doing nothing   
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (independent_list[i].party != "")
        {
            inde_counter++;
        }
        else
        {
            // Doing nothing   
        }
    }



    sentor_counter = dem_counter + repu_counter + inde_counter;

    if (sentor_counter == 0)
    {
        std::cout << "Sorry currently no sentors in data base. " << std::endl;
    }
    else
    {
        // Displaying number of Sentors
        std::cout << "Total number of Democrats: " << dem_counter << std::endl;
        std::cout << "Total number of Republicans: " << repu_counter << std::endl;
        std::cout << "Total number of Independent: " << inde_counter << std::endl;
        std::cout << "Total number of Senators: " << sentor_counter << std::endl;
        
        std::cout << std::endl;

        float dem_percentage = 0.00f;
        float repu_percentage = 0.00f;
        float inde_percentage = 0.00f;

        dem_percentage = dem_counter * 100 / sentor_counter;
        repu_percentage = repu_counter * 100 / sentor_counter;
        inde_percentage = inde_counter * 100 / sentor_counter;



        std::cout << "Democrats: " << dem_percentage << "%" << std::endl;
        std::cout << "Republicans: " << repu_percentage << "%" << std::endl;
        std::cout << "Independents: " << inde_percentage << "%" << std::endl;

        std::cout << std::endl;

        if (dem_percentage > repu_percentage && dem_percentage > inde_percentage)
        {
            std::cout << "[Party In Majorty] " << "Democrats: " << dem_percentage << "%";
        }
        else if (repu_percentage > dem_percentage && repu_percentage > inde_percentage)
        {
            std::cout << "[Party In Majorty] " << "Republicans: " << repu_percentage << "%";
        }
        else if (inde_percentage > dem_percentage && inde_percentage > repu_percentage)
        {
            std::cout << "[Party In Majorty] " << "Independents: " << dem_percentage << "%";
        }



        std::cout << std::endl;
    }

}




void automatic_loading()
{

    int x = 1;
    int selection;
    int name_counter = 0;


    std::string party_1;
    std::string first_name_1;
    std::string last_name_1;
    std::string state_1;

        
        
            while (in_coming >> party_1 >> first_name_1 >> last_name_1 >> state_1)
            {
                name_counter++;

                if (party_1 == "Democrat")
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (democrat_list[i].first_name == "")
                        {
                            democrat_list[i].party = party_1;
                            democrat_list[i].first_name = first_name_1;
                            democrat_list[i].last_name = last_name_1;
                            democrat_list[i].state = state_1;
                            break;
                        }
                        else
                        {
                            // skip
                        }
                    }
                }
                else if (party_1 == "Republican")
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (republican_list[i].first_name == "")
                        {
                            republican_list[i].party = party_1;
                            republican_list[i].first_name = first_name_1;
                            republican_list[i].last_name = last_name_1;
                            republican_list[i].state = state_1;
                            break;
                        }

                    }
                }
                else if (party_1 == "Independent")
                {
                    for (int i = 0; i < 10; i++)
                    {
                        if (independent_list[i].first_name == "")
                        {
                            independent_list[i].party = party_1;
                            independent_list[i].first_name = first_name_1;
                            independent_list[i].last_name = last_name_1;
                            independent_list[i].state = state_1;
                            break;
                        }

                    }
                }
                // end of while loop
            }

            system("cls");
            std::cout << name_counter << " Names have been downloaded." << std::endl;
            total_names = name_counter;
        
        

}










bool  Scaning_names(bool red_flag, std::string first_name_2, std::string last_name_2)
{

  


    //checking if name already in data base
    for (int i = 0; i < 100; i++)
    {
        if (democrat_list[i].first_name == first_name_2 && democrat_list[i].last_name == last_name_2)
        {
            std::cout << "Name already in data base! " << std::endl;
            std::cout << "Listed as: Democrat " << std::endl;
            red_flag = true;
            break;
        }
        else
        {
            // continue looping till done
        }

    }


    //checking if name already in data base
    for (int i = 0; i < 100; i++)
    {
        if (republican_list[i].first_name == first_name_2 && republican_list[i].last_name == last_name_2)
        {
            std::cout << "Name already in data base! " << std::endl;
            std::cout << "Listed as: Republican " << std::endl;
            red_flag = true;
            break;
        }
        else
        {
            // continue looping till done
        }

    }

    


    //checking if name already in data base
    for (int i = 0; i < 100; i++)
    {
        if (independent_list[i].first_name == first_name_2 && independent_list[i].last_name == last_name_2)
        {
            std::cout << "Name already in data base! " << std::endl;
            std::cout << "Listed as: Independent " << std::endl;
            red_flag = true;
            break;
        }
        else
        {
            // continue looping till done
        }

    }



    return red_flag;
}





