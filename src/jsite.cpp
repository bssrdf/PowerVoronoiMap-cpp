#include "jsite.h"

/**
 * Representing a site with the polygon.
 * @author nocaj
 *
 */
public class JSite extends JPolygon {
private static Random rand=new Random();

    private Site site;
    boolean pressed=false;
    public JSite(final Site site){
        this(rand.nextInt());
        this.site=site;
        this.addMouseMotionListener(new MouseMotionListener() {

            @Override
            public void mouseMoved(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            synchronized public void mouseDragged(MouseEvent e) {
                // TODO Auto-generated method stub


                    Point point = e.getPoint();
                    double dx=getLocation().getX();
                    double dy=getLocation().getY();

                    double x = point.getX()+dx;
                    double y = point.getY()+dy;
                    site.setXY(x, y);

                    PowerBox.powerBox.computeDiagram();

            }
        });
        this.addMouseListener(new MouseListener() {


            @Override
            public synchronized void mouseReleased(MouseEvent e) {
                if (pressed){
                    Point point = e.getPoint();
                    double dx=getLocation().getX();
                    double dy=getLocation().getY();

                    double x = point.getX()+dx;
                    double y = point.getY()+dy;
                    site.setXY(x, y);
                    }
                    PowerBox.powerBox.computeDiagram();
                    pressed=false;
            }

            @Override
            public void mousePressed(MouseEvent e) {
                Point point = e.getPoint();
                double currentX=point.getX();
                double currentY=point.getY();
                if (site.distance(new Site(currentX, currentY))<10){
                    pressed=true;
                }

            }

            @Override
            public void mouseExited(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            public void mouseEntered(MouseEvent e) {
                // TODO Auto-generated method stub

            }

            @Override
            public void mouseClicked(MouseEvent mouseEvent) {
                 int modifiers = mouseEvent.getModifiers();
                    if ((modifiers & InputEvent.BUTTON1_MASK) == InputEvent.BUTTON1_MASK) {
                      System.out.println("Left button pressed.");
                        site.setWeight(Math.pow((Math.sqrt(site.getWeight())+10),2));
                    }
                    if ((modifiers & InputEvent.BUTTON2_MASK) == InputEvent.BUTTON2_MASK) {
                      System.out.println("Middle button pressed.");
                    }
                    if ((modifiers & InputEvent.BUTTON3_MASK) == InputEvent.BUTTON3_MASK) {
                        site.setWeight(Math.pow((Math.sqrt(site.getWeight())-10),2));
                    }

            }
        });
    }


    public JSite(Integer id) {
        super(id);
    }

    protected void setSite(Site site) {
        this.site = site;
    }

    protected Site getSite() {
        return site;
    }

    @Override
        public void paintComponent(Graphics g) {
            // TODO Auto-generated method stub
//			super.paintComponent(g);
        }
    @Override
        public boolean contains(int x, int y) {
            double distance = new kn.uni.voronoitreemap.j2d.Point2D(x+this.getLocation().x, y+this.getLocation().y).distance(site.getX(), site.getY());
            if (distance<10){
                return true;
            }
            return false;
        }

    @Override
        public boolean contains(Point p) {
        return contains((int)p.getX(), (int)p.getY());
        }
    /**
     *
     */
    private static final long serialVersionUID = 1L;

}
