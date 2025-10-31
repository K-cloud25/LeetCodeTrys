# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        if not root:
            return "#"
        res, q = [], deque([root])
        while q:
            n = q.popleft()
            if n:
                res.append(str(n.val))
                q.append(n.left)
                q.append(n.right)
            else:
                res.append("#")
        return ",".join(res)

        

    def deserialize(self, data):
        if data=="#":
            return None
        nodes = data.split(",")
        root = TreeNode(int(nodes[0]))
        q = deque([root])
        i = 1
        while q:
            curr = q.popleft()
            if nodes[i] != "#":
                curr.left = TreeNode(int(nodes[i]))
                q.append(curr.left)
            i+= 1
            if i<len(nodes) and nodes[i] != "#":
                curr.right = TreeNode(int(nodes[i]))
                q.append(curr.right)
            i+=1
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))