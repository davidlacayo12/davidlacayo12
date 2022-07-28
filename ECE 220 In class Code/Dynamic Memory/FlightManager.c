#include <stdio.h>
#include <stdlib.h>

int main(){

}

int AddFlight(Flight *newPlane, Flight **list){ 
 
Flight *previous = NULL;  
Flight *current = *list;  
int IDcompare; 

 while (current != NULL) {
    IDcompare = strcmp(newPlane->ID, current->ID); 
    // returns 0 if equal
    // < 0 if newPlane->ID is less than current->ID 
    // > 0 if newPlane->ID is greater than current->ID
    if (IDcompare == 0) 
        return -1;
    else if (IDcompare < 0) {
    // Add newPlane in between previous and current nodes newPlane->next = current;
        newPlane->next = current;
        if (previous == NULL) 
            *list = newPlane;       //Add at head 
        else 
            previous->next = newPlane; // Add to Middle 
        return 0;                                 
        }
        else{
            previous = current;
            current = current->next; // Continue traversing thru the list previous = current;
        }        
    } 
    newPlane->next = NULL;
    if(previous == NULL){
        *list= newPlane;        //empty List
    }
    else    
        previous->next = newPlane;  //add at tail
    return 0;
}

int DeleteFlight(char *planeID, Flight **list){
    Flight *previous = NULL;
    Flight *current = *list;
    int IDcompare;
    
    while (current != NULL){
        IDcompare = strcmp(planeID, current->ID); 
    // returns 0 if equal
    // < 0 if newPlane->ID is less than current->ID 
    // > 0 if newPlane->ID is greater than current->ID
    if (IDcompare == 0){
        //Found node to remove 
        if(previous == NULL)
            *list = current->next;  //del at head
        else
            previous->next = current->next;     //del from Mid/Tail
    }
    else if (IDcompare < 0)
        return -1;   //doesn't exist
    else{
        //Continue traversing through the list
        previous = current;
        current = current->next;
        }
    }
    //Traversed the whole list. doesn't exist
    return -1;
}


typedef struct flightType Flight;
struct flightType{
    char ID[7];// Max 6 characters 
    int altitude;// in meters
    int longitude;// in tenths of degrees
    int latitude;// in tenths of degrees
    int heading;// in tenths of degrees
    double airSpeed; // in kilometers/hour
Flight *next;// Pointer to next element 
};

Flight *CreateFlight(char *ID, int altitude, int longitude, int latitude, int heading, double airspeed){
    Flight *newFlight;
    newFlight = (Flight *)malloc(sizeof(Flight));
    strcpy(newFlight->ID, ID);
    newFlight->altitude = altitude;
    newFlight->longitude = longitude;
    newFlight->latitude = latitude;
    newFlight->heading = heading;
    newFlight->airSpeed = airspeed;
}