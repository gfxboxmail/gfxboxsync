const status = document.getElementById('status');
const analyze = document.getElementById('analyze');
const apply = document.getElementById('apply');

let proposals = [];

analyze.addEventListener('click', () => {
  status.textContent = 'Native audio analysis is ready to be connected to Premiere clip audio exports.';
  apply.disabled = false;
  proposals = [{ track: 0, clip: 0, offsetSeconds: 0 }];
});

apply.addEventListener('click', () => {
  if (!proposals.length) return;

  // Timeline operations must be performed only after explicit Apply.
  // The implementation will call Premiere scripting APIs to adjust clip start times;
  // source media will not be overwritten or rendered.
  status.textContent = 'Preview complete. No source media will be modified.';
});
