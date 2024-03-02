
'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

#Function to return a list containing elements of left view of the binary tree.
def leftViewUtil(root,level,max_level,result):
    if root is None:
        return
    
    if level > max_level[0]:
        result.append(root.data)
        max_level[0] = level
    
    leftViewUtil(root.left,level+1,max_level,result)
    leftViewUtil(root.right,level+1,max_level,result)
    

def LeftView(root):
    
    # code here
    result = []
    max_level = [0]
    leftViewUtil(root,1,max_level,result)
    return result
