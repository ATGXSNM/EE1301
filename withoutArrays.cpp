#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define LENGTH 100

int main() 
{
  int resistance00,resistance01,resistance02,resistance03,resistance04,resistance05,resistance06,resistance07,resistance08,resistance09,
      resistance10,resistance11,resistance12,resistance13,resistance14,resistance15,resistance16,resistance17,resistance18,resistance19,
      resistance20,resistance21,resistance22,resistance23,resistance24,resistance25,resistance26,resistance27,resistance28,resistance29,
      resistance30,resistance31,resistance32,resistance33,resistance34,resistance35,resistance36,resistance37,resistance38,resistance39,
      resistance40,resistance41,resistance42,resistance43,resistance44,resistance45,resistance46,resistance47,resistance48,resistance49,
      resistance50,resistance51,resistance52,resistance53,resistance54,resistance55,resistance56,resistance57,resistance58,resistance59,
      resistance60,resistance61,resistance62,resistance63,resistance64,resistance65,resistance66,resistance67,resistance68,resistance69,
      resistance70,resistance71,resistance72,resistance73,resistance74,resistance75,resistance76,resistance77,resistance78,resistance79,
      resistance80,resistance81,resistance82,resistance83,resistance84,resistance85,resistance86,resistance87,resistance88,resistance89,
      resistance90,resistance91,resistance92,resistance93,resistance94,resistance95,resistance96,resistance97,resistance98,resistance99;
  float average;
  int min = 10000; // bigger than all input values
  int max = 0;    // smaller than all input values

  ifstream fin;
  fin.open("resistors.txt");

  if(!fin.is_open()){
    cout << "Couldn't open file resistors.txt\n";
  }

  // read all the resistors into the array
  fin >> resistance00; fin.ignore(10,'\n');
  fin >> resistance01; fin.ignore(10,'\n');
  fin >> resistance02; fin.ignore(10,'\n');
  fin >> resistance03; fin.ignore(10,'\n');
  fin >> resistance04; fin.ignore(10,'\n');
  fin >> resistance05; fin.ignore(10,'\n');
  fin >> resistance06; fin.ignore(10,'\n');
  fin >> resistance07; fin.ignore(10,'\n');
  fin >> resistance08; fin.ignore(10,'\n');
  fin >> resistance09; fin.ignore(10,'\n');
  fin >> resistance10; fin.ignore(10,'\n');
  fin >> resistance11; fin.ignore(10,'\n');
  fin >> resistance12; fin.ignore(10,'\n');
  fin >> resistance13; fin.ignore(10,'\n');
  fin >> resistance14; fin.ignore(10,'\n');
  fin >> resistance15; fin.ignore(10,'\n');
  fin >> resistance16; fin.ignore(10,'\n');
  fin >> resistance17; fin.ignore(10,'\n');
  fin >> resistance18; fin.ignore(10,'\n');
  fin >> resistance19; fin.ignore(10,'\n');
  fin >> resistance20; fin.ignore(10,'\n');
  fin >> resistance21; fin.ignore(10,'\n');
  fin >> resistance22; fin.ignore(10,'\n');
  fin >> resistance23; fin.ignore(10,'\n');
  fin >> resistance24; fin.ignore(10,'\n');
  fin >> resistance25; fin.ignore(10,'\n');
  fin >> resistance26; fin.ignore(10,'\n');
  fin >> resistance27; fin.ignore(10,'\n');
  fin >> resistance28; fin.ignore(10,'\n');
  fin >> resistance29; fin.ignore(10,'\n');
  fin >> resistance30; fin.ignore(10,'\n');
  fin >> resistance31; fin.ignore(10,'\n');
  fin >> resistance32; fin.ignore(10,'\n');
  fin >> resistance33; fin.ignore(10,'\n');
  fin >> resistance34; fin.ignore(10,'\n');
  fin >> resistance35; fin.ignore(10,'\n');
  fin >> resistance36; fin.ignore(10,'\n');
  fin >> resistance37; fin.ignore(10,'\n');
  fin >> resistance38; fin.ignore(10,'\n');
  fin >> resistance39; fin.ignore(10,'\n');
  fin >> resistance40; fin.ignore(10,'\n');
  fin >> resistance41; fin.ignore(10,'\n');
  fin >> resistance42; fin.ignore(10,'\n');
  fin >> resistance43; fin.ignore(10,'\n');
  fin >> resistance44; fin.ignore(10,'\n');
  fin >> resistance45; fin.ignore(10,'\n');
  fin >> resistance46; fin.ignore(10,'\n');
  fin >> resistance47; fin.ignore(10,'\n');
  fin >> resistance48; fin.ignore(10,'\n');
  fin >> resistance49; fin.ignore(10,'\n');
  fin >> resistance50; fin.ignore(10,'\n');
  fin >> resistance51; fin.ignore(10,'\n');
  fin >> resistance52; fin.ignore(10,'\n');
  fin >> resistance53; fin.ignore(10,'\n');
  fin >> resistance54; fin.ignore(10,'\n');
  fin >> resistance55; fin.ignore(10,'\n');
  fin >> resistance56; fin.ignore(10,'\n');
  fin >> resistance57; fin.ignore(10,'\n');
  fin >> resistance58; fin.ignore(10,'\n');
  fin >> resistance59; fin.ignore(10,'\n');
  fin >> resistance60; fin.ignore(10,'\n');
  fin >> resistance61; fin.ignore(10,'\n');
  fin >> resistance62; fin.ignore(10,'\n');
  fin >> resistance63; fin.ignore(10,'\n');
  fin >> resistance64; fin.ignore(10,'\n');
  fin >> resistance65; fin.ignore(10,'\n');
  fin >> resistance66; fin.ignore(10,'\n');
  fin >> resistance67; fin.ignore(10,'\n');
  fin >> resistance68; fin.ignore(10,'\n');
  fin >> resistance69; fin.ignore(10,'\n');
  fin >> resistance70; fin.ignore(10,'\n');
  fin >> resistance71; fin.ignore(10,'\n');
  fin >> resistance72; fin.ignore(10,'\n');
  fin >> resistance73; fin.ignore(10,'\n');
  fin >> resistance74; fin.ignore(10,'\n');
  fin >> resistance75; fin.ignore(10,'\n');
  fin >> resistance76; fin.ignore(10,'\n');
  fin >> resistance77; fin.ignore(10,'\n');
  fin >> resistance78; fin.ignore(10,'\n');
  fin >> resistance79; fin.ignore(10,'\n');
  fin >> resistance80; fin.ignore(10,'\n');
  fin >> resistance81; fin.ignore(10,'\n');
  fin >> resistance82; fin.ignore(10,'\n');
  fin >> resistance83; fin.ignore(10,'\n');
  fin >> resistance84; fin.ignore(10,'\n');
  fin >> resistance85; fin.ignore(10,'\n');
  fin >> resistance86; fin.ignore(10,'\n');
  fin >> resistance87; fin.ignore(10,'\n');
  fin >> resistance88; fin.ignore(10,'\n');
  fin >> resistance89; fin.ignore(10,'\n');
  fin >> resistance90; fin.ignore(10,'\n');
  fin >> resistance91; fin.ignore(10,'\n');
  fin >> resistance92; fin.ignore(10,'\n');
  fin >> resistance93; fin.ignore(10,'\n');
  fin >> resistance94; fin.ignore(10,'\n');
  fin >> resistance95; fin.ignore(10,'\n');
  fin >> resistance96; fin.ignore(10,'\n');
  fin >> resistance97; fin.ignore(10,'\n');
  fin >> resistance98; fin.ignore(10,'\n');
  fin >> resistance99; fin.ignore(10,'\n');
  fin.close();

  // calculate the average, min, and max values
  // ONLY CALCULATING AVERAGE, OTHERS ARE WAY TOO MUCH WORK!!!

  // calculate average
  average = resistance00+resistance01+resistance02+resistance03+resistance04+resistance05+resistance06+resistance07+resistance08+resistance09
    +resistance10+resistance11+resistance12+resistance13+resistance14+resistance15+resistance16+resistance17+resistance18+resistance19
    +resistance20+resistance21+resistance22+resistance23+resistance24+resistance25+resistance26+resistance27+resistance28+resistance29
    +resistance30+resistance31+resistance32+resistance33+resistance34+resistance35+resistance36+resistance37+resistance38+resistance39
    +resistance40+resistance41+resistance42+resistance43+resistance44+resistance45+resistance46+resistance47+resistance48+resistance49
    +resistance50+resistance51+resistance52+resistance53+resistance54+resistance55+resistance56+resistance57+resistance58+resistance59
    +resistance60+resistance61+resistance62+resistance63+resistance64+resistance65+resistance66+resistance67+resistance68+resistance69
    +resistance70+resistance71+resistance72+resistance73+resistance74+resistance75+resistance76+resistance77+resistance78+resistance79
    +resistance80+resistance81+resistance82+resistance83+resistance84+resistance85+resistance86+resistance87+resistance88+resistance89
    +resistance90+resistance91+resistance92+resistance93+resistance94+resistance95+resistance96+resistance97+resistance98+resistance99;

  // finalize the average by dividing by number of samples
  average /= (float)LENGTH;
 
  // calculate min
  min = (resistance00 < min)?resistance00:min;
  min = (resistance01 < min)?resistance01:min;
  min = (resistance02 < min)?resistance02:min;
  min = (resistance03 < min)?resistance03:min;
  min = (resistance04 < min)?resistance04:min;
  min = (resistance05 < min)?resistance05:min;
  min = (resistance06 < min)?resistance06:min;
  min = (resistance07 < min)?resistance07:min;
  min = (resistance08 < min)?resistance08:min;
  min = (resistance09 < min)?resistance09:min;
  min = (resistance10 < min)?resistance10:min;
  min = (resistance11 < min)?resistance11:min;
  min = (resistance12 < min)?resistance12:min;
  min = (resistance13 < min)?resistance13:min;
  min = (resistance14 < min)?resistance14:min;
  min = (resistance15 < min)?resistance15:min;
  min = (resistance16 < min)?resistance16:min;
  min = (resistance17 < min)?resistance17:min;
  min = (resistance18 < min)?resistance18:min;
  min = (resistance19 < min)?resistance19:min;
  min = (resistance20 < min)?resistance20:min;
  min = (resistance21 < min)?resistance21:min;
  min = (resistance22 < min)?resistance22:min;
  min = (resistance23 < min)?resistance23:min;
  min = (resistance24 < min)?resistance24:min;
  min = (resistance25 < min)?resistance25:min;
  min = (resistance26 < min)?resistance26:min;
  min = (resistance27 < min)?resistance27:min;
  min = (resistance28 < min)?resistance28:min;
  min = (resistance29 < min)?resistance29:min;
  min = (resistance30 < min)?resistance30:min;
  min = (resistance31 < min)?resistance31:min;
  min = (resistance32 < min)?resistance32:min;
  min = (resistance33 < min)?resistance33:min;
  min = (resistance34 < min)?resistance34:min;
  min = (resistance35 < min)?resistance35:min;
  min = (resistance36 < min)?resistance36:min;
  min = (resistance37 < min)?resistance37:min;
  min = (resistance38 < min)?resistance38:min;
  min = (resistance39 < min)?resistance39:min;
  min = (resistance40 < min)?resistance40:min;
  min = (resistance41 < min)?resistance41:min;
  min = (resistance42 < min)?resistance42:min;
  min = (resistance43 < min)?resistance43:min;
  min = (resistance44 < min)?resistance44:min;
  min = (resistance45 < min)?resistance45:min;
  min = (resistance46 < min)?resistance46:min;
  min = (resistance47 < min)?resistance47:min;
  min = (resistance48 < min)?resistance48:min;
  min = (resistance49 < min)?resistance49:min;
  min = (resistance50 < min)?resistance50:min;
  min = (resistance51 < min)?resistance51:min;
  min = (resistance52 < min)?resistance52:min;
  min = (resistance53 < min)?resistance53:min;
  min = (resistance54 < min)?resistance54:min;
  min = (resistance55 < min)?resistance55:min;
  min = (resistance56 < min)?resistance56:min;
  min = (resistance57 < min)?resistance57:min;
  min = (resistance58 < min)?resistance58:min;
  min = (resistance59 < min)?resistance59:min;
  min = (resistance60 < min)?resistance60:min;
  min = (resistance61 < min)?resistance61:min;
  min = (resistance62 < min)?resistance62:min;
  min = (resistance63 < min)?resistance63:min;
  min = (resistance64 < min)?resistance64:min;
  min = (resistance65 < min)?resistance65:min;
  min = (resistance66 < min)?resistance66:min;
  min = (resistance67 < min)?resistance67:min;
  min = (resistance68 < min)?resistance68:min;
  min = (resistance69 < min)?resistance69:min;
  min = (resistance70 < min)?resistance70:min;
  min = (resistance71 < min)?resistance71:min;
  min = (resistance72 < min)?resistance72:min;
  min = (resistance73 < min)?resistance73:min;
  min = (resistance74 < min)?resistance74:min;
  min = (resistance75 < min)?resistance75:min;
  min = (resistance76 < min)?resistance76:min;
  min = (resistance77 < min)?resistance77:min;
  min = (resistance78 < min)?resistance78:min;
  min = (resistance79 < min)?resistance79:min;
  min = (resistance80 < min)?resistance80:min;
  min = (resistance81 < min)?resistance81:min;
  min = (resistance82 < min)?resistance82:min;
  min = (resistance83 < min)?resistance83:min;
  min = (resistance84 < min)?resistance84:min;
  min = (resistance85 < min)?resistance85:min;
  min = (resistance86 < min)?resistance86:min;
  min = (resistance87 < min)?resistance87:min;
  min = (resistance88 < min)?resistance88:min;
  min = (resistance89 < min)?resistance89:min;
  min = (resistance90 < min)?resistance90:min;
  min = (resistance91 < min)?resistance91:min;
  min = (resistance92 < min)?resistance92:min;
  min = (resistance93 < min)?resistance93:min;
  min = (resistance94 < min)?resistance94:min;
  min = (resistance95 < min)?resistance95:min;
  min = (resistance96 < min)?resistance96:min;
  min = (resistance97 < min)?resistance97:min;
  min = (resistance98 < min)?resistance98:min;
  min = (resistance99 < min)?resistance99:min;

  // calculate max
  max = (resistance00 > max)?resistance00:max;
  max = (resistance01 > max)?resistance01:max;
  max = (resistance02 > max)?resistance02:max;
  max = (resistance03 > max)?resistance03:max;
  max = (resistance04 > max)?resistance04:max;
  max = (resistance05 > max)?resistance05:max;
  max = (resistance06 > max)?resistance06:max;
  max = (resistance07 > max)?resistance07:max;
  max = (resistance08 > max)?resistance08:max;
  max = (resistance09 > max)?resistance09:max;
  max = (resistance10 > max)?resistance10:max;
  max = (resistance11 > max)?resistance11:max;
  max = (resistance12 > max)?resistance12:max;
  max = (resistance13 > max)?resistance13:max;
  max = (resistance14 > max)?resistance14:max;
  max = (resistance15 > max)?resistance15:max;
  max = (resistance16 > max)?resistance16:max;
  max = (resistance17 > max)?resistance17:max;
  max = (resistance18 > max)?resistance18:max;
  max = (resistance19 > max)?resistance19:max;
  max = (resistance20 > max)?resistance20:max;
  max = (resistance21 > max)?resistance21:max;
  max = (resistance22 > max)?resistance22:max;
  max = (resistance23 > max)?resistance23:max;
  max = (resistance24 > max)?resistance24:max;
  max = (resistance25 > max)?resistance25:max;
  max = (resistance26 > max)?resistance26:max;
  max = (resistance27 > max)?resistance27:max;
  max = (resistance28 > max)?resistance28:max;
  max = (resistance29 > max)?resistance29:max;
  max = (resistance30 > max)?resistance30:max;
  max = (resistance31 > max)?resistance31:max;
  max = (resistance32 > max)?resistance32:max;
  max = (resistance33 > max)?resistance33:max;
  max = (resistance34 > max)?resistance34:max;
  max = (resistance35 > max)?resistance35:max;
  max = (resistance36 > max)?resistance36:max;
  max = (resistance37 > max)?resistance37:max;
  max = (resistance38 > max)?resistance38:max;
  max = (resistance39 > max)?resistance39:max;
  max = (resistance40 > max)?resistance40:max;
  max = (resistance41 > max)?resistance41:max;
  max = (resistance42 > max)?resistance42:max;
  max = (resistance43 > max)?resistance43:max;
  max = (resistance44 > max)?resistance44:max;
  max = (resistance45 > max)?resistance45:max;
  max = (resistance46 > max)?resistance46:max;
  max = (resistance47 > max)?resistance47:max;
  max = (resistance48 > max)?resistance48:max;
  max = (resistance49 > max)?resistance49:max;
  max = (resistance50 > max)?resistance50:max;
  max = (resistance51 > max)?resistance51:max;
  max = (resistance52 > max)?resistance52:max;
  max = (resistance53 > max)?resistance53:max;
  max = (resistance54 > max)?resistance54:max;
  max = (resistance55 > max)?resistance55:max;
  max = (resistance56 > max)?resistance56:max;
  max = (resistance57 > max)?resistance57:max;
  max = (resistance58 > max)?resistance58:max;
  max = (resistance59 > max)?resistance59:max;
  max = (resistance60 > max)?resistance60:max;
  max = (resistance61 > max)?resistance61:max;
  max = (resistance62 > max)?resistance62:max;
  max = (resistance63 > max)?resistance63:max;
  max = (resistance64 > max)?resistance64:max;
  max = (resistance65 > max)?resistance65:max;
  max = (resistance66 > max)?resistance66:max;
  max = (resistance67 > max)?resistance67:max;
  max = (resistance68 > max)?resistance68:max;
  max = (resistance69 > max)?resistance69:max;
  max = (resistance70 > max)?resistance70:max;
  max = (resistance71 > max)?resistance71:max;
  max = (resistance72 > max)?resistance72:max;
  max = (resistance73 > max)?resistance73:max;
  max = (resistance74 > max)?resistance74:max;
  max = (resistance75 > max)?resistance75:max;
  max = (resistance76 > max)?resistance76:max;
  max = (resistance77 > max)?resistance77:max;
  max = (resistance78 > max)?resistance78:max;
  max = (resistance79 > max)?resistance79:max;
  max = (resistance80 > max)?resistance80:max;
  max = (resistance81 > max)?resistance81:max;
  max = (resistance82 > max)?resistance82:max;
  max = (resistance83 > max)?resistance83:max;
  max = (resistance84 > max)?resistance84:max;
  max = (resistance85 > max)?resistance85:max;
  max = (resistance86 > max)?resistance86:max;
  max = (resistance87 > max)?resistance87:max;
  max = (resistance88 > max)?resistance88:max;
  max = (resistance89 > max)?resistance89:max;
  max = (resistance90 > max)?resistance90:max;
  max = (resistance91 > max)?resistance91:max;
  max = (resistance92 > max)?resistance92:max;
  max = (resistance93 > max)?resistance93:max;
  max = (resistance94 > max)?resistance94:max;
  max = (resistance95 > max)?resistance95:max;
  max = (resistance96 > max)?resistance96:max;
  max = (resistance97 > max)?resistance97:max;
  max = (resistance98 > max)?resistance98:max;
  max = (resistance99 > max)?resistance99:max;

  cout << "Average, Min, Max resistance: " << average << ", " << min << ", "<< max << endl;

  return 0;
}
