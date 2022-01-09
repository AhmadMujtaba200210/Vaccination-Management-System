#include<iostream>
#include<cmath>
using namespace std;
int hasFn(string key, int ts) {
	int idx = 0;
	int power = 1;
	for (auto ch : key) {
		idx = (idx + ch * power) % ts;
		power = (power * 29) % ts;
	}
	return idx;
}



void centresVacc(string str) {
	if (str == "islamabad") { cout << ""; }
	else if (str == "lahore") {
		cout << "Quaid e Azam International Hospital, Street 9, G-8/2 G 8/2 G-8, Islamabad \t Contact Numbers \t 051-8449100/03345083009" << endl;
		cout << "NIRM, Near Murree Express Highway Islamabad \t Contact Numbers \t 051-9262213/03315377687" << endl;
		cout << "Akbar Niazi Teaching Hospital, Mohran Jejan, Islamabad \t Contact Numbers \t 051-8153000/03335233785" << endl;
		cout << "PIMS Hospital G-8/3, Bhara Kahu, Islamabad \t Contact Numbers \t 051-9261170/ 03332371584" << endl;
		cout << "Polyclinic, Chakshahzad Islamabad \t Contact Numbers \t 051-9220379/ 03003272441" << endl;
		cout << "National Institute of Health (NIH) Vaccination Center, Islamabad, G- Kashmir Hwy, 1, Service Road South, G 9/1 G-9, Islamabad \t Contact Numbers 051-9255566/03319816350" << endl;

	}
	else if (str == "lahore") {
		cout << "";
		cout << "Indus Hospital, Sabzazar \t Contact Numbers \t 0321-4196605 " << endl;
		cout << "Indus Hospital, Raiwind \t Contact Numbers \t 0333-9699948  " << endl;
		cout << "National Hospital, DHA Phase-1, Lahore \t Contact Numbers \t 0309-7060786  " << endl;
		cout << "Data Darbar, Lower Mall, Lahore \t Contact Numbers \t 0324-4673454 " << endl;
		cout << "United Christian Hospital, Main Boulevard, Gulberg \t Contact Numbers \t 03134073644" << endl;
	}
	else if (str == "dikhan") {
		cout << "";
		cout << " BHU Gomal University" << endl;
		cout << "BHU Jabbar Wala" << endl;
		cout << "BHU Maddi Khel " << endl;
		cout << "BHU Giloty" << endl;
		cout << "BHU Maddi Khel " << endl;
	}
	else if (str == "multan") {
		cout << "GOVT. MUSHTAQ LANG THQ HOSP.JALALPUR PIRWALA" << endl;
		cout << "NISHTER INSTITUTE OF DENTISTRY" << endl;
		cout << "Pak Italian Modern Burn Centre, Nishtar Medical University Multan " << endl;
		cout << "Rural Health Centre Makhdoom Rashid" << endl;
		cout << "ddho office,jalalpur pirwala" << endl;
		cout << "Government WAPDA Hospital Multan " << endl;
	}
	else if (str == "faislabad") {
		cout << "" << endl;
		cout << "Rural Health Centre Khurrianwala" << endl;
		cout << "Sports Complex Chak Jhumra" << endl;
		cout << "THQ HOSPITAL CHAK JGovernment WAPDA Hospital Multan HUMRA" << endl;
		cout << "THQ HOSPITAL SUMUNDRI " << endl;
		cout << "THQ Hospital New Building, Tandlianwala" << endl;
	}
	else if (str == "gujranwala") {
		cout << "AC office Kamoke " << endl;
		cout << "Rural Health Center, Ali Pur Chatha , Wazirabad, Gujranwala" << endl;
		cout << "Rural Health Center, Kot Ladha , Nowshera Virkan, Gujranwala" << endl;
		cout << "Wapda Hospital, Gujranwala" << endl;
		cout << "Cantt. General Hospital, Rawali Cantt. Gujranwala " << endl;
		cout << "Commnuity School Hall, Wapda Town, Gujranwala" << endl;

	}
	else if (str == "peshawar") {
		cout << "Hayat Abad Medical Complex Hayatabad 1" << endl;
		cout << "Cantt General Hospital Peshawar" << endl;
		cout << "AL-Khidmat Hospital" << endl;
		cout << "Bacha Khan Air port" << endl;
		cout << "Cantt General Hospital Peshawar" << endl;
		cout << "Clerk Colony/Civil quartar Nothia Qadeem" << endl;

	}
}





