package linkedList;

class Node {
    protected int data;
    protected Node link;

    public Node() {
        link = null;
        data = 0;
    }

    public Node(int d, Node l) {
        data = d;
        link = l;
    }

    public void setLink(Node n) {
        link = n;
    }

    public void setData(int d) {
        data = d;
    }

    public Node getLink() {
        return link;
    }

    public int getData() {
        return data;
    }
}