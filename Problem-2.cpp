// TC : O(V+E)
// SC : O(V+E)
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses == 0)
        {
            return false;
        }
        // store indegree of element
        vector<int> indegree(numCourses, 0);
        // store outdegree of element
        map<int, vector<int>> hashMap;
        queue<int> curStore;
        int count = 0;

        // update indegree and outdegree of an element
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int to = prerequisites[i][0];
            int from = prerequisites[i][1];
            indegree[to]++;
            hashMap[from].push_back(to);
        }

        // push elements with 0 indegree to the queue
        // topological sort
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                curStore.push(i);
                count++;
            }
        }

        // update the indegree if the dependent course is completed for the element
        // by updating the indegree
        while (!curStore.empty())
        {
            int curr = curStore.front();
            int s = hashMap[curr].size();
            for (int i = 0; i < s; i++)
            {
                indegree[hashMap[curr][i]]--;
                if (indegree[hashMap[curr][i]] == 0)
                {
                    curStore.push(hashMap[curr][i]);
                    count++;
                }
            }
            curStore.pop();
        }

        // check if all the courses are completed
        return numCourses == count;
    }
};