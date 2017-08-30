package eagles;

public class CylinderComputation {

	public static void main(String[] args) {
		double radius, height, surfaceArea, volume;
		final double Pi = 3.14159265;
		radius = 5.097;
		height = 12.4828545;
		surfaceArea = (2*Pi*radius*height)+(2*Pi*radius*radius);
		volume = Pi*radius*radius*height;
		System.out.println("the volume is "+ volume+" and the surface area is "+surfaceArea );
				
	}

}

