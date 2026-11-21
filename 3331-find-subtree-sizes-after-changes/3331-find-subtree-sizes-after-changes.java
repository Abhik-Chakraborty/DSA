class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        List<List<Integer>> tree = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }

        for (int i = 1; i < n; i++) {
            tree.get(parent[i]).add(i);
        }

        int[] ans = new int[n];
        Arrays.fill(ans, 1);

        int[] lastSeen = new int[26];
        Arrays.fill(lastSeen, -1);

        dfs(0, -1, s, tree, ans, lastSeen);

        return ans;
    }
    private void dfs(
            int node,
            int parent,
            String s,
            List<List<Integer>> tree,
            int[] ans,
            int[] lastSeen) {

        int ch = s.charAt(node) - 'a';
        int previous = lastSeen[ch];
        lastSeen[ch] = node;

        for (int child : tree.get(node)) {
            dfs(child, node, s, tree, ans, lastSeen);
        }

        if (previous != -1) {
            ans[previous] += ans[node];

        } else if (parent != -1) {
            ans[parent] += ans[node];
        }
        lastSeen[ch] = previous;
    }
}