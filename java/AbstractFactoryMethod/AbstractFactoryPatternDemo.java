package AbstractFactoryMethod;

public class AbstractFactoryPatternDemo {
    public static void main(String[] args) {
        AbstractFactory shapeFactory = FactoryProducer.getFactory(false);

        Shape shape1 = shapeFactory.getShape("rectangle");
        shape1.draw();

        Shape shape2 = shapeFactory.getShape("square");
        shape2.draw();

        AbstractFactory shapeFactory2 = FactoryProducer.getFactory(true);

        Shape shape3 = shapeFactory2.getShape("rectangle");
        shape3.draw();

        Shape shape4 = shapeFactory2.getShape("square");
        shape4.draw();

    }
    
}
