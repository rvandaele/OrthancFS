#include "../include/OrthancCppClient.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(int argc,char * argv[]){
	try{
    	OrthancClient::Initialize("../lib/libOrthancClient.so");
    }
    catch (OrthancClient::OrthancClientException e){
    	cerr << "EXCEPTION: [" << e.What() << "]" << std::endl;
    	return -1;
  	}

    // Display the content of the local Orthanc instance
    OrthancClient::OrthancConnection orthanc("http://localhost:8042");
	cout << "Patient count : " << orthanc.GetPatientCount() << endl;
	for(int i=0;i<orthanc.GetPatientCount();i++){
		OrthancClient::Patient p = orthanc.GetPatient(i);
		cout << "identifiant patient: " << p.GetMainDicomTag("PatientName","B. Obama") << endl;
		for(int j=0;j<p.GetStudyCount();j++){
			OrthancClient::Study s = p.GetStudy(j);
			cout << "	identifiant etude: " << s.GetMainDicomTag("StudyDescription","Medical Data : Study") << endl;
			for(int k=0;k<s.GetSeriesCount();k++){
				OrthancClient::Series se = s.GetSeries(k);
				cout <<  "		identifiant serie: " << se.GetMainDicomTag("SeriesDescription","Medical Data : Series") << endl;
				for(int l=0;l<se.GetInstanceCount();l++){
					OrthancClient::Instance in = se.GetInstance(l);
					//try{					
						cout <<  "			identifiant serie: " << in.GetDicomSize() << endl;	
					//}
					//catch(OrthancClient::OrthancException e){
					//	cout << "nope" << endl;
					//}
					//int v = in.GetTagAsFloat("SOPInstanceUID");
				}
			}	
		}
	}
	
	return EXIT_SUCCESS;
}
