// CS1010 Programming Methodology
// Problem Set 1 Exercise #22: packing.c

//
// Packing
//
//
// Lau Yan Han

#include <stdio.h>

int Case_1(int tray_l, int tray_b, int slab_l, int slab_b);
int Case_2(int tray_l, int tray_b, int slab_l, int slab_b);

int Case_1(int tray_l, int tray_b, int slab_l, int slab_b) //Case 1: slab length to tray length, slab breadth to tray breadth
{
    int fill_l; int fill_b;
    int tray_area; int slab_area;
    int remaining_area_1;

    fill_l = tray_l/slab_l; //fill_l is the maximum number of slab lengths that can be arranged along the tray length
    fill_b = tray_b/slab_b; //fill_b is the maximum number of slab breadths that can be arranged along the tray breadth

    slab_area = (slab_l*fill_l) * (slab_b*fill_b); //This is the maximum area taken up by all the slabs
    //slab_l*fill_l --> total number of slabs arranged along the length, multiplied by length of each slab. Equivalent for slab_b
    tray_area = tray_l * tray_b; //Total area taken up by the tray
    remaining_area_1 = tray_area - slab_area; //remaining area = area of tray - area of slab

    return remaining_area_1;
}

int Case_2(int tray_l, int tray_b, int slab_l, int slab_b)
{ //Same as Case 1 except slab lengths align to tray breadth, and slab breadth align to tray length
    int fill_l; int fill_b;
    int tray_area; int slab_area;
    int remaining_area_2;

    fill_l = tray_l/slab_b;
    fill_b = tray_b/slab_l;

    slab_area = (slab_b*fill_l) * (slab_l*fill_b);
    tray_area = tray_l * tray_b;
    remaining_area_2 = tray_area - slab_area;

    return remaining_area_2;
}

int main(void) {

    int tray_l; int tray_b; //Tray length and tray breadth
    int slab_l; int slab_b; //Slab length and slab breadth
    int min_unused_area;

	printf("Enter size of tray: ");
	scanf ("%d %d", &tray_l,&tray_b);
	printf("Enter size of slab: ");
    scanf ("%d %d", &slab_l,&slab_b); //Test 2 possible cases and return the smaller value
    if (Case_1(tray_l,tray_b,slab_l,slab_b) > Case_2(tray_l,tray_b,slab_l,slab_b)){ //See whether value from Case 1 is greater than Case 2 or vice versa
        min_unused_area = Case_2(tray_l,tray_b,slab_l,slab_b); //If Case 1 returns a larger value, take Case 2 (which is smaller)
    }
    else {
        min_unused_area = Case_1(tray_l,tray_b,slab_l,slab_b); //If Case 2 is larger, take Case 1 (which is smaller)
    } //Basically take the smaller of either value

	printf("Minimum unused area = %d\n",min_unused_area);

	return 0;
}
