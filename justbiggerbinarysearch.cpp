long long int binarySearch(long long int sortedArray[], long long int toFind, long long int len)
{
    // Returns index of toFind in sortedArray, or -1 if not found
    long long int l = 0;
    long long int h = len - 1;
    long long int mid;

    while(l < h){
      mid = l + (h-l+1)/2;
      if(sortedArray[mid] > toFind){
        h = mid-1;
      }else{
        l = mid;
      }
    }
    if(sortedArray[l] > toFind) return -1;
    return l;
}
