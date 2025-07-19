class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
            # Sort the folder paths so that parent folders come before subfolders
            # Sorting takes care of ordering so all subfolders of the current main folder come after it
        folder.sort()
        result = []

        for path in folder:
            # If result is empty or current path is not a subfolder of the last path in result
            if not result or not path.startswith(result[-1] + '/'):
                result.append(path)

        return result
            