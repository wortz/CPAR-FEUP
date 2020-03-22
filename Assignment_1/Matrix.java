import java.util.Scanner;
public class Matrix{

    public static void main(String args[]){
        switch (args[0]) {
            case "1":
                onMult(Integer.parseInt(args[1]),Integer.parseInt(args[2]));
                break;
        
            case "2":
                onMultLine(Integer.parseInt(args[1]),Integer.parseInt(args[2]));
                break;
        }
    }

    private static void onMult(int m_ar, int m_br){
        double[] pha = new double[m_ar*m_br];
        double[] phb = new double[m_ar*m_br];
        double[] phc = new double[m_ar*m_br];


        for(int i=0;i<m_ar;i++){
            for(int w=0;w<m_br;w++){
                pha[i*m_ar+w]=(double)1.0;
                phb[i*m_ar+w]=(double)(i+1);
            }
        }

        long startTime = System.currentTimeMillis();
        for(int i=0; i<m_ar; i++){
        	for(int w=0; w<m_br; w++){
            	int temp = 0;
			    for(int k=0; k<m_ar; k++){	
				    temp += pha[i*m_ar+w] * phb[k*m_ar+w];
			    }
			    phc[i*m_ar+w]=temp;
		    }
        }
        long diffTime = (System.currentTimeMillis() - startTime);
        System.out.println("Time: " + diffTime + " ms");
    }

    private static void onMultLine(int m_ar, int m_br){
        double[] pha = new double[m_ar*m_br];
        double[] phb = new double[m_ar*m_br];
        double[] phc = new double[m_ar*m_br];


        for(int i=0;i<m_ar;i++){
            for(int w=0;w<m_ar;w++){
                pha[i*m_ar+w]=(double)1.0;
                phb[i*m_ar+w]=(double)(i+1);
            }
        }

        long startTime = System.currentTimeMillis();
        for(int i=0; i<m_ar; i++){
        	for(int w=0; w<m_br; w++){
			    for(int k=0; k<m_ar; k++){	
				    phc[i*m_ar+k] += pha[i*m_ar+k] * phb[w*m_ar+k];
			    }
		    }
        }
        long diffTime = (System.currentTimeMillis() - startTime);
        System.out.println("Time: " + diffTime + " ms");
    }

}