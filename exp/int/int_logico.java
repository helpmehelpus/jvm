/*
 * Compile assim: javac int_logico.java -target 1.2 -source 1.2
 */
public class int_logico{
	public static void main(String args[]){
		int a=13; /*1010*/
		int array[] = {5,5,6};
		
		System.out.println(a); /*Tem que dar 8*/
		
		if(array[0]==array[1]) System.out.println("indice 0 igual a indice 1");	
		if(array[0]!=array[2]) System.out.println("indice 0 diferente de indice 2");	

	}
}
