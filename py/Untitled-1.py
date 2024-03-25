import numpy as np
A=np.array([[1,2,3],
            [3,4,-3],
            [9,-7,2]
]
)
print(A)
A.shape
print(A[1:3][0:3])
det=np.linalg.det(A)
print(det)

def cramer  (A,b):
    # A nın matris b nin onun vektörü olduğunun kontrölü
    if len(A.shape) !=2 or len(b.shape) !=1:
        print("A ve b yanlış boyutlarda")
        return None
    if A.shape[0] != A.shape[1]:
        print("A kare matris değil")
        return None
    if A.shape[0] != b.shape[0]:
        print("A ve b boyutları uyumsuz")
        return None
    
    x= np.zeros(A.shape[0])
    A_i= np.empty_like(A)
    
    for i in range(A.shape[0]):
        A_i= A.copy()
        A_i[:,i]=b
        x[i]=np.linalg.det(A_i)/np.linalg.det(A)

    return x