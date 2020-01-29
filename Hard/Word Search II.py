class TrieNode():
    def __init__(self):
        self.leaf = collections.defaultdict(TrieNode)
        self.isWord = False


class Trie():
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for w in word:
            node = node.leaf[w]
        node.isWord = True


class Solution(object):
    def findWords(self, board, words):
        retList = []
        trie = Trie()
        node = trie.root

        for word in words:
            trie.insert(word)

        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(board, node, i, j, "", retList)

        return retList

    def dfs(self, board, node, i, j, path, retList):
        if node.isWord:
            retList.append(path)
            node.isWord = False

        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return

        charHere = board[i][j]
        node = node.children.get(charHere)
        if not node:
            return

        board[i][j] = "#"
        self.dfs(board, node, i + 1, j, path + charHere, retList)
        self.dfs(board, node, i - 1, j, path + charHere, retList)
        self.dfs(board, node, i, j - 1, path + charHere, retList)
        self.dfs(board, node, i, j + 1, path + charHere, retList)
        board[i][j] = charHere