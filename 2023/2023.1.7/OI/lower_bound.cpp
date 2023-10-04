int *lower_bound(int *first,int *last,int key){
    register int mid,left=0,right=last-first;
    while(left<right){
        mid=(left+right)>>1;
        if(*(first+mid)<key) left=mid+1;
        else right=mid;
    }
    return first+left;
}