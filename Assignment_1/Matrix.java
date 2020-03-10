public class Matrix{

    public static void main(String args[]){
        onMult(1000,1000);
    }

    private static void onMult(int m_ar, int m_br){
        double[][] pha = new double[m_ar][m_ar];
        double[][] phb = new double[m_ar][m_ar];
        double[][] phc = new double[m_ar][m_ar];


        for(int i=0;i<m_ar;i++){
            for(int w=0;w<m_ar;w++){
                pha[i][w]=(double)1.0;
                phb[i][w]=(double)(i+1);
            }
        }

        long startTime = System.nanoTime();

        for(int i=0; i<m_ar; i++){
        	for(int w=0; w<m_br; w++){
            	int temp = 0;
			    for(int k=0; k<m_ar; k++){	
				    temp += pha[i][w] * phb[k][w];
			    }
			    phc[i][w]=temp;
		    }
	    }

        long endTime = System.nanoTime();
        long duration = (endTime - startTime);
        System.out.println(duration);
        for(int i=0; i<1; i++)
        {	for(int j=0; j<m_ar; j++)
                System.out.print(phc[i][j] + " ");
            System.out.println();
        }
    }

}