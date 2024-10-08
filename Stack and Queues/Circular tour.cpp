class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       int start = 0; 
	   int end = 1; 

	   int curr_petrol = p[start].petrol - p[start].distance; 

	   while (end != start || curr_petrol < 0) 
	   { 
	        while (curr_petrol < 0 && start != end) 
		    { 
			    curr_petrol -= p[start].petrol - p[start].distance; 
			    start = (start + 1) % n; 
                
                if (start == 0) 
			        return -1; 
		    } 
    
    		curr_petrol += p[end].petrol - p[end].distance; 

	    	end = (end + 1) % n; 
	    } 

	return start; 
    }
};
