import heapq
import pickle  #saves entire python obj into a file and to load it back

class Node:
    def __init__(self,char,freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    def __lt__(self,other):
        return self.freq < other.freq
    
def build_tree(freq):
    heap = []
    for char in freq:
        node = Node(char, freq[char]) #creating the node
        heapq.heappush(heap, node)  #putting node in heap
    while len(heap) > 1:    #build the tree till one node
        left = heapq.heappop(heap)  #smallest node
        right = heapq.heappop(heap)    #second smallest node
        new_node = Node(None, left.freq + right.freq)
        new_node.left = left
        new_node.right = right

        heapq.heappush(heap, new_node)  #putting combined node back to heap

    return heap[0]  # root at 0

def get_codes(root):
    codes={}
    def make_code(node, code):
        if node.char is not None:
            codes[node.char] = code
            return
        make_code(node.left, code + "0")
        make_code(node.right, code + "1")
    make_code(root,"")
    return codes

def compress(input_file, output_file):
    with open(input_file, "r", encoding="utf-8") as file:
        text = file.read()
    if text == "":
        print("File is empty.")
        return
    
    freq = {}

    for char in text:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

    root = build_tree(freq) #build tree

    codes = get_codes(root)  # generate huffman codes

    print("Huffman Codes:")

    for char in codes:
        print(repr(char), ":", codes[char])

    encoded = ""
    for char in text:
        encoded += codes[char]

    padding = 8 - (len(encoded) % 8)

    encoded += "0" * padding

    data = bytearray()  # Convert every 8 bits into one byte

    for i in range(0, len(encoded), 8):
        byte = encoded[i:i + 8]
        data.append(int(byte, 2))

    compressed = {
        "tree": root,
        "padding": padding,
        "data": bytes(data)
    }

    # Write compressed data to file
    with open(output_file, "wb") as file:
        pickle.dump(compressed, file)

    print("\nFile compressed successfully.")

    print("Original size:",len(text.encode("utf-8")),"bytes")

    print("Compressed size:",len(data),"bytes")


def decompress(input_file, output_file):
    with open(input_file, "rb") as file:
        compressed = pickle.load(file)

    root = compressed["tree"]
    padding = compressed["padding"]
    data = compressed["data"]

    #back to binary
    encoded = ""

    for byte in data:
        encoded += format(byte, "08b")

    if padding != 0:
        encoded = encoded[:-padding]

    text = ""
    current = root

    for bit in encoded:

        if bit == "0":
            current = current.left
        else:
            current = current.right

        if current.char is not None:

            text += current.char
            current = root

    with open(output_file, "w", encoding="utf-8") as file:
        file.write(text)

    print("\nFile decompressed successfully.")

compress("input.txt", "compressed.huff")
decompress("compressed.huff", "output.txt")




